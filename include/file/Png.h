//
// Created by uroborosq on 14.12.22.
//

#ifndef HOROSHOEDITOR_PNG_H
#define HOROSHOEDITOR_PNG_H

#include "AbstractFile.h"

class Png : public AbstractFile {
public:
    std::vector<float> read(const std::string &path) override;
    void write(const std::string &path, const std::vector<float> &pixels, FileImageInfo imageInfo) override;
    FileImageInfo getImageInfo() override;
    bool checkHeader(const  char *) override;
private:
    FileImageInfo info{};
    std::vector<unsigned char*> pallet;
    std::vector<float> data;
    short bytesPerPixel;
    unsigned char *compressedData = nullptr;
    unsigned long compressedDataPointer = 0;
    static int bigEndianBytesToInt(const unsigned char *);
    static unsigned char* intToBigEndianBytes(int);
//    static uint8_t* decodeWithZlib(const uint8_t* data, int size, int availableSize, int* outputSize);
    static uint8_t* decodeWithLibdeflate(const uint8_t* data, unsigned long size, unsigned long availableSize, int* output);

    void parsePallet(const unsigned char* palletChunk, int length);
    void parseHeader(const unsigned char* headerData);
    void joinDataChunk(const unsigned char* dataChunk, int length);
    unsigned char *undoFilterScanline(unsigned char *scanline, unsigned char *previousScanline) const;
    void composeDate();
    static const unsigned char* buildHeaderData(FileImageInfo info_);
    static const unsigned char* buildChunk(int length, const unsigned char* chunkData, const char* type);
};

#endif //HOROSHOEDITOR_PNG_H
