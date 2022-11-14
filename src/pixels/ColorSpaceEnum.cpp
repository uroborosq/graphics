//
// Created by uroborosq on 14.11.22.
//
#include "ColorSpaceEnum.h"

AbstractColorSpace* chooseConverter(const ColorSpace& colorSpace_) {
    switch (colorSpace_) {
        case ColorSpace::CMY:
            return new CMYColorSpace();
        case HSL:
            return new HSLColorSpace();
        case HSV:
            return new HSVColorSpace();
        case YCbCr_601:
            return new YCbCr_601ColorSpace();
        case YCbCr_709:
            return new YCbCr_709ColorSpace();
        case YCoCg:
            return new YCoCgColorSpace();
        default:
            return nullptr;
    }
}