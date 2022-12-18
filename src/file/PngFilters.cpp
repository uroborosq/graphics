//
// Created by uroborosq on 17.12.22.
//
#include <cmath>
#include "PngFilters.h"

unsigned char *
SubPngFilter::applyFilter(const unsigned char *scanline, const unsigned char *previousScanline, unsigned long size,
                          short channelsNumber) {
    auto *newScanline = new unsigned char[size];

    for (int i = 0; i < channelsNumber; i++)
        newScanline[i] = scanline[i];

    for (int i = channelsNumber; i < size; i++) {
        newScanline[i] = scanline[i] - scanline[i - channelsNumber];
    }
    return newScanline;
}
unsigned char *
SubPngFilter::undoFilter(const unsigned char *scanline, const unsigned char *previousScanline, unsigned long size,
                         short channelsNumber) {
    auto *newScanline = new unsigned char[size];

    for (int i = 0; i < channelsNumber; i++)
        newScanline[i] = scanline[i];

    for (int i = 1; i < size; i++) {
        newScanline[i] = scanline[i] + newScanline[i - channelsNumber];
    }
    return newScanline;
}

unsigned char *
UpPngFilter::applyFilter(const unsigned char *scanline, const unsigned char *previousScanline, unsigned long size,
                         short channelsNumber) {
    auto *newScanline = new unsigned char[size];
    for (int i = 0; i < size; i++) {
        newScanline[i] = scanline[i] - previousScanline[i];
    }
    return newScanline;
}

unsigned char *
UpPngFilter::undoFilter(const unsigned char *scanline, const unsigned char *previousScanline, unsigned long size,
                        short channelsNumber) {
    auto *newScanline = new unsigned char[size];
    for (int i = 0; i < size; i++) {
        newScanline[i] = scanline[i] + previousScanline[i];
    }
    return newScanline;
}

unsigned char *AveragePngFilter::applyFilter(const unsigned char *scanline, const unsigned char *previousScanline,
                                             unsigned long size,
                                             short channelsNumber) {
    auto *newScanline = new unsigned char[size];

    for (int i = 0; i < channelsNumber; i++)
        newScanline[i] = scanline[i] - (unsigned char)std::floor(previousScanline[i] / 2);

    for (int i = channelsNumber; i < size; i++) {
        newScanline[i] =
                scanline[i] - (unsigned char) (std::floor(((unsigned short)(scanline[i - channelsNumber]) + (unsigned short)(previousScanline[i])) / 2));
    }
    return newScanline;
}

unsigned char *
AveragePngFilter::undoFilter(const unsigned char *scanline, const unsigned char *previousScanline, unsigned long size,
                             short channelsNumber) {
    auto newScanline = new unsigned char[size];
    for (int i = 0; i < channelsNumber; i++)
        newScanline[i] = scanline[i] + (unsigned char)std::floor(previousScanline[i] / 2);
    for (int i = channelsNumber; i < size; i++) {
        newScanline[i] = scanline[i] + (unsigned char)std::floor((int(newScanline[i - channelsNumber] + int(previousScanline[i]))) / 2);
    }
    return newScanline;
}

unsigned char *
PaethPngFilter::applyFilter(const unsigned char *scanline, const unsigned char *previousScanline, unsigned long size,
                            short channelsNumber) {
    auto newScanline = new unsigned char[size];
    for (int i = 0; i < channelsNumber; i++)
        newScanline[i] = scanline[i] - paethPredictor(0, previousScanline[i], 0);
    for (int i = channelsNumber; i < size; i++) {
        newScanline[i] = scanline[i] - paethPredictor(scanline[i - channelsNumber], previousScanline[i], previousScanline[i - channelsNumber]);
    }
    return newScanline;
}

unsigned char *
PaethPngFilter::undoFilter(const unsigned char *scanline, const unsigned char *previousScanline, unsigned long size,
                           short channelsNumber) {
    auto newScanline = new unsigned char[size];
    for (int i = 0; i < channelsNumber; i++)
        newScanline[i] = scanline[i] + paethPredictor(0, previousScanline[i], 0);

    for (int i = channelsNumber; i < size; i++) {
        newScanline[i] = scanline[i] + paethPredictor(newScanline[i - channelsNumber], previousScanline[i], previousScanline[i - channelsNumber]);
    }
    return newScanline;
}

unsigned char PaethPngFilter::paethPredictor(unsigned char a, unsigned char b, unsigned char c) {
    auto p = a + b - c;
    auto pa = abs(p - a);
    auto pb = abs(p - b);
    auto pc = abs(p - c);

    if (pa <= pb && pa <= pc) {
        return a;
    } else if (pb <= pc) {
        return b;
    }
    return c;
}

AbstractPngFilter *getPngFilter(PngFilter filter) {
    switch (filter) {
        case Up:
            return new UpPngFilter();
        case Sub:
            return new SubPngFilter();
        case Average:
            return new AveragePngFilter();
        case Paeth:
            return new PaethPngFilter();
        default:
            return nullptr;
    }
}
