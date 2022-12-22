//
// Created by uroborosq on 14.12.22.
//

#ifndef HOROSHOEDITOR_FILEIMAGEINFO_H
#define HOROSHOEDITOR_FILEIMAGEINFO_H

#include "FileFormatType.h"

struct FileImageInfo {
    int height;
    int width;
    unsigned char depth;
    float gamma;
    int channels;
    FileFormatType fileFormat;
};

#endif //HOROSHOEDITOR_FILEIMAGEINFO_H
