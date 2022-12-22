//
// Created by uroborosq on 17.12.22.
//

#ifndef HOROSHOEDITOR_PNGFILTERS_H
#define HOROSHOEDITOR_PNGFILTERS_H

class AbstractPngFilter {
public:
    virtual unsigned char *
    applyFilter(const unsigned char *scanline, const unsigned char *previousScanline, unsigned long size,
                short channelsNumber) = 0;
    virtual unsigned char *
    undoFilter(const unsigned char *scanline, const unsigned char *previousScanline, unsigned long size,
               short channelsNumber) = 0;
};

enum PngFilter {
    None,
    Sub,
    Up,
    Average,
    Paeth
};

AbstractPngFilter* getPngFilter(PngFilter filter);

class SubPngFilter : public AbstractPngFilter{
public:
    unsigned char *applyFilter(const unsigned char *scanline, const unsigned char *previousScanline, unsigned long size,
                               short channelsNumber) override;

    unsigned char *undoFilter(const unsigned char *scanline, const unsigned char *previousScanline, unsigned long size,
                              short channelsNumber) override;
};

class UpPngFilter : public AbstractPngFilter {
public:
    unsigned char *applyFilter(const unsigned char *scanline, const unsigned char *previousScanline, unsigned long size,
                               short channelsNumber) override;

    unsigned char *undoFilter(const unsigned char *scanline, const unsigned char *previousScanline, unsigned long size,
                              short channelsNumber) override;
};

class AveragePngFilter : public AbstractPngFilter {
public:
    unsigned char *applyFilter(const unsigned char *scanline, const unsigned char *previousScanline, unsigned long size,
                               short channelsNumber) override;

    unsigned char *undoFilter(const unsigned char *scanline, const unsigned char *previousScanline, unsigned long size,
                              short channelsNumber) override;
};

class PaethPngFilter : public AbstractPngFilter {
public:
    unsigned char *applyFilter(const unsigned char *scanline, const unsigned char *previousScanline, unsigned long size,
                               short channelsNumber) override;

    unsigned char *undoFilter(const unsigned char *scanline, const unsigned char *previousScanline, unsigned long size,
                              short channelsNumber) override;
private:
    static unsigned char paethPredictor(unsigned char a, unsigned char b, unsigned char c);
};

#endif //HOROSHOEDITOR_PNGFILTERS_H
