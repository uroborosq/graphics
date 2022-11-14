//
// Created by uroborosq on 14.11.22.
//

#ifndef HOROSHOEDITOR_COLORSPACEENUM_H
#define HOROSHOEDITOR_COLORSPACEENUM_H

#include "CMYColorSpace.h"
#include "HSVColorSpace.h"
#include "YCbCr_601ColorSpace.h"
#include "YCbCr_709ColorSpace.h"
#include "YCoCgColorSpace.h"
#include "HSLColorSpace.h"

enum ColorSpace {
    RGB,
    HSL,
    HSV,
    CMY,
    YCbCr_601,
    YCbCr_709,
    YCoCg,
};

AbstractColorSpace* chooseConverter(const ColorSpace&);
#endif //HOROSHOEDITOR_COLORSPACEENUM_H
