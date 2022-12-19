//
// Created by uroborosq on 14.12.22.
//

#include <fstream>
#include "Png.h"
#include "libdeflate.h"
#include <cmath>
#include "PngFilters.h"
#include <algorithm>

std::vector<float> Png::read(const std::string &path) {

    data.clear();
    pallet.clear();
    info = FileImageInfo{};
    compressedDataPointer = 0;
    auto input = std::ifstream(path, std::ios::in | std::ios::binary);
    char header[8];
    input.read(header, 8);

    if (input.fail()) {
        throw std::invalid_argument("PNG: Файл не найден");
    }

    if (!checkHeader(header)) {
        throw std::invalid_argument("PNG: File format is not supported");
    }
    info.gamma = 0;
    while (!input.eof()) {
        unsigned char funnyBuffer[4];
        char chunkTypeChrArr[5];

        input.read((char *) funnyBuffer, 4);
        int chunkLength = bigEndianBytesToInt(funnyBuffer);

        auto *chunkData = new uint8_t[chunkLength];

        input.read(chunkTypeChrArr, sizeof(char) * 4);
        input.read((char *) chunkData, chunkLength);
        input.read((char *) funnyBuffer, sizeof(int));

        auto checkSum = (unsigned int) bigEndianBytesToInt(funnyBuffer);

        auto typeAndData = new unsigned char[chunkLength + 4];
        for (int i = 0; i < 4; i++) typeAndData[i] = chunkTypeChrArr[i];
        for (int i = 4; i < chunkLength + 4; i++) typeAndData[i] = chunkData[i - 4];

        if (checkSum != libdeflate_crc32(0, typeAndData, chunkLength + 4))
            throw std::invalid_argument("PNG: File is corrupted: check sum doesn't match");


        delete[] typeAndData;

        chunkTypeChrArr[4] = '\0';
        std::string chunkType = chunkTypeChrArr;
        if (chunkType == "IHDR")
            parseHeader(chunkData);
        else if (chunkType == "PLTE")
            parsePallet(chunkData, chunkLength);
        else if (chunkType == "IDAT")
            joinDataChunk(chunkData, chunkLength);
        else if (chunkType == "IEND")
            break;
        else if (chunkType == "gAMA")
            info.gamma = (float) bigEndianBytesToInt((unsigned char *) chunkData) / 100000.0f;

        delete[] chunkData;
    }

    composeDate();

    input.close();
    return data;

}

void Png::write(const std::string &path, const std::vector<float> &pixels, FileImageInfo imageInfo) {
    std::ofstream output(path, std::ios::out | std::ios::binary);
    uint8_t correctHeader[]{0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A};
    output.write((char *) correctHeader, 8);

    auto chunkData = buildHeaderData(imageInfo);
    auto chunk = buildChunk(13, chunkData, "IHDR");
    output.write((char *) chunk, 25);

    if (imageInfo.gamma != 0) {
        auto gamma = (int) (imageInfo.gamma * 100000.0f);
        auto buffer = intToBigEndianBytes(gamma);

        chunk = buildChunk(4, buffer, "gAMA");
        output.write((char *) chunk, 16);
        delete[] buffer;
        delete[] chunk;
    }

    auto previousScanline = new unsigned char[imageInfo.width * imageInfo.channels];
    std::fill(previousScanline, previousScanline + imageInfo.width * imageInfo.channels, 0);

    auto decompressedBytes = new unsigned char[imageInfo.width * (imageInfo.height) * imageInfo.channels +
                                               +imageInfo.height];
    for (int i = 0; i < imageInfo.height; i++) {
        auto scanline = new unsigned char[imageInfo.width * imageInfo.channels];
        for (int j = 0; j < imageInfo.width * imageInfo.channels; j++) {
            scanline[j] = (unsigned char) std::round(pixels[i * imageInfo.width * imageInfo.channels + j]);
        }
        int bestFilter = 0;
        int bestAmountOfZeros = 0;

        for (int j = 0; j < imageInfo.width * imageInfo.channels; j++) {
            if (scanline[j] == 0)
                bestAmountOfZeros++;
        }

        for (int f = 1; f < 5; f++) {
            int currentAmountOfZeros = 0;
            auto filter = getPngFilter(static_cast<PngFilter>(f));
            auto filtered = filter->applyFilter(scanline, previousScanline, imageInfo.width * imageInfo.channels,
                                                (short) imageInfo.channels);
            for (int z = 0; z < imageInfo.width * imageInfo.channels; z++) {
                if (filtered[z] == 0)
                    currentAmountOfZeros++;
            }
            if (currentAmountOfZeros > bestAmountOfZeros) {
                bestFilter = f;
                bestAmountOfZeros = currentAmountOfZeros;
            }
            delete[] filtered;
        }
        auto filter = getPngFilter(static_cast<PngFilter>(bestFilter));
        decompressedBytes[i * imageInfo.width * imageInfo.channels + i] = bestFilter;

        unsigned char *filtered;
        if (filter == nullptr) {
            filtered = new unsigned char[imageInfo.width * imageInfo.channels];
            std::copy(scanline, scanline + imageInfo.width * imageInfo.channels, filtered);
        } else {
            filtered = filter->applyFilter(scanline,
                                           previousScanline,
                                           imageInfo.width * imageInfo.channels, (short) imageInfo.channels);
        }
        std::copy(filtered, filtered + imageInfo.width * imageInfo.channels,
                  decompressedBytes + i * imageInfo.width * imageInfo.channels + i + 1);
        delete[] previousScanline;
        previousScanline = scanline;
    }
    delete[] previousScanline;


    auto compressor = libdeflate_alloc_compressor(6);

    if (compressor == nullptr) throw std::bad_alloc();
    unsigned int availableSize = imageInfo.width * imageInfo.height * imageInfo.channels + imageInfo.height;
    auto compressedBytes = new unsigned char[availableSize];
    unsigned long outputSize;
    while (true) {
        outputSize = libdeflate_zlib_compress(compressor, decompressedBytes,
                                              imageInfo.width * imageInfo.height * imageInfo.channels +
                                              imageInfo.height, compressedBytes,
                                              availableSize);
        if (outputSize == 0) {
            availableSize *= 2;
            delete[] compressedBytes;
            compressedBytes = new unsigned char[availableSize];
        } else {
            break;
        }
    }
    for (int i = 0; i < outputSize; i += 8192) {
        auto actualLength = std::min(std::min(outputSize - i, outputSize), (unsigned long) 8192);
        chunk = buildChunk((int) actualLength, compressedBytes + i, "IDAT");
        output.write((char *) chunk, (int) actualLength + 12);
    }
    char nothing[4]{0, 0, 0, 0};
    for (int i = 0; i < 4; i++) output.write(nothing, 1);
    output.write("IEND", 4);
    unsigned char controlSum[]{0xAE, 0x42, 0x60, 0x82};
    output.write((char *) controlSum, 4);
    output.close();
}

FileImageInfo Png::getImageInfo() {
    return info;
}

bool Png::checkHeader(const char *header) {
    uint8_t correctHeader[]{0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A};
    for (int i = 0; i < 8; i++) {
        if (uint8_t(header[i]) != correctHeader[i]) {
            return false;
        }
    }
    return true;
}

int Png::bigEndianBytesToInt(const unsigned char *bytes) {
    return bytes[3] | (bytes[2] << 8) | (bytes[1] << 16) | (bytes[0] << 24);
}

uint8_t *Png::decodeWithLibdeflate(const uint8_t *data, unsigned long size, unsigned long availableSize, std::size_t *output) {
    auto decompressor = libdeflate_alloc_decompressor();
    auto decompressedBytes = new uint8_t[availableSize];
    if (decompressor == nullptr)
        throw std::bad_alloc();
    while (true) {
        auto result = libdeflate_zlib_decompress(decompressor, data, size,
                                                 decompressedBytes,
                                                 availableSize, output);
        if (result == LIBDEFLATE_SUCCESS) {
            break;
        } else if (result == LIBDEFLATE_BAD_DATA) {
            throw std::invalid_argument("PNG: File is corrupted");
        } else if (result == LIBDEFLATE_SHORT_OUTPUT) {
            throw std::invalid_argument("PNG: хз я не понял чо в доках написано про эту ошибку");
        } else if (result == LIBDEFLATE_INSUFFICIENT_SPACE) {
            delete[] decompressedBytes;
            availableSize *= 2;
            decompressedBytes = new uint8_t[availableSize];
        }
    }
    libdeflate_free_decompressor(decompressor);
    return decompressedBytes;
}

void Png::parsePallet(const unsigned char *palletChunk, int length) {
    for (int i = 0; i < length; i += info.channels) {
        auto pixel = new unsigned char[info.channels];
        for (int j = 0; j < info.channels; j++) {
            pixel[j] = palletChunk[i + j];
        }
        pallet.push_back(pixel);
    }
}

void Png::parseHeader(const unsigned char *headerData) {
    unsigned char funnyBuffer[4];
    for (int i = 0; i < 4; i++)
        funnyBuffer[i] = headerData[i];
    info.width = bigEndianBytesToInt(funnyBuffer);
    for (int i = 4; i < 8; i++)
        funnyBuffer[i - 4] = headerData[i];
    info.height = bigEndianBytesToInt(funnyBuffer);
    info.depth = (unsigned char) headerData[8];

    if (info.depth != 8) {
        throw std::invalid_argument("PNG: only 8bit depth supported");
    }

    auto colorType = headerData[9];
    if (colorType == 0) {
        info.fileFormat = PngColorType0;
        info.channels = 1;
        bytesPerPixel = 1;
    } else if (colorType == 2) {
        info.fileFormat = PngColorType2;
        info.channels = 3;
        bytesPerPixel = 3;
    } else if (colorType == 3) {
        info.fileFormat = PngColorType3;
        info.channels = 3;
        bytesPerPixel = 1;
    } else {
        throw std::invalid_argument("PNG: format is unsupported");
    }
    compressedData = new unsigned char[bytesPerPixel * info.width * info.height];
}

void Png::joinDataChunk(const unsigned char *dataChunk, int length) {
    if (compressedData == nullptr) {
        throw std::invalid_argument("PNG: File is corrupted: IHDR chunk is not before IDAT or not exists");
    }
    for (unsigned long i = 0; i < length; i++) {
        compressedData[compressedDataPointer + i] = (unsigned char) dataChunk[i];
    }
    compressedDataPointer += length;
}

unsigned char *Png::undoFilterScanline(unsigned char *scanline, unsigned char *previousScanline) const {
    auto filter = getPngFilter(
            static_cast<PngFilter>(scanline[0]));

    if (filter == nullptr) {
        auto newScanline = new unsigned char[info.width * bytesPerPixel];
        for (int i = 0; i < info.width * bytesPerPixel; i++) newScanline[i] = scanline[i + 1];
        return newScanline;
    }

    return filter->undoFilter(scanline + 1, previousScanline, info.width * bytesPerPixel, bytesPerPixel);
}

void Png::composeDate() {
    std::size_t outputSize;
    std::size_t availableOutputSize = info.height * info.width * bytesPerPixel;

    auto decompressedBytes = decodeWithLibdeflate(compressedData, compressedDataPointer,
                                                  availableOutputSize, &outputSize);


    auto *previous = new unsigned char[info.width * bytesPerPixel];
    for (int j = 0; j < info.width * bytesPerPixel; j++) previous[j] = 0;

    for (int i = 0; i < info.height; i++) {
        auto *scanline = undoFilterScanline(decompressedBytes + info.width * i * bytesPerPixel + i, previous);

        if (info.fileFormat == PngColorType3) {
            for (int j = 0; j < info.width * bytesPerPixel; j++) {
                auto pixelComposition = pallet[scanline[j]];
                for (int k = 0; k < info.channels; k++) {
                    data.push_back(float(pixelComposition[k]));
                }
            }
        } else {
            for (int j = 0; j < info.width * bytesPerPixel; j++) {
                data.push_back(float(scanline[j]));
            }
        }

        delete[] previous;
        previous = scanline;
    }
    delete[] previous;
    delete[] decompressedBytes;
}

unsigned char *Png::intToBigEndianBytes(int number) {
    auto bytes = new unsigned char[4];
    bytes[0] = (number & 0xFF000000) >> 24;
    bytes[1] = (number & 0x00FF0000) >> 16;
    bytes[2] = (number & 0x0000FF00) >> 8;
    bytes[3] = number & 0x000000FF;
    return bytes;
}

const unsigned char *Png::buildHeaderData(FileImageInfo info_) {
    auto chunk = new unsigned char[13];

    auto buffer = intToBigEndianBytes(info_.width);
    std::copy(buffer, buffer + 4, chunk);
    delete[] buffer;

    buffer = intToBigEndianBytes(info_.height);
    std::copy(buffer, buffer + 4, chunk + 4);
    delete[] buffer;

    chunk[8] = info_.depth;

    chunk[9] = info_.channels == 3 ? 2 : 0;
    chunk[10] = 0;
    chunk[11] = 0;
    chunk[12] = 0;
    return chunk;
}

const unsigned char *Png::buildChunk(int length, const unsigned char *chunkData, const char *type) {
    auto chunk = new unsigned char[12 + length];
    auto intBuffer = intToBigEndianBytes(length);
    std::copy(intBuffer, intBuffer + 4, chunk);
    delete[] intBuffer;
    std::copy(type, type + 4, chunk + 4);
    std::copy(chunkData, chunkData + length, chunk + 8);
    auto checkSum = libdeflate_crc32(0, chunk + 4, length + 4);
    intBuffer = intToBigEndianBytes((int) checkSum);
    std::copy(intBuffer, intBuffer + 4, chunk + 8 + length);
    delete[] intBuffer;
    return chunk;
}