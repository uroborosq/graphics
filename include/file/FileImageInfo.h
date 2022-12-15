//
// Created by uroborosq on 14.12.22.
//

#ifndef HOROSHOEDITOR_FILEIMAGEINFO_H
#define HOROSHOEDITOR_FILEIMAGEINFO_H

#include "FileFormat.h"

struct FileImageInfo {
    int height;
    int width;
    int pallet;
    float gamma;
    int channels;
    FileFormat fileFormat;
};

#endif //HOROSHOEDITOR_FILEIMAGEINFO_H
