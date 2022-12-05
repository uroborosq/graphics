#include <cmath>
#include "sRGBColorSpace.h"

std::vector<float> &sRGBColorSpace::toLinearRGB(std::vector<float>& pixels)
{
    for (float & pixel : pixels)
        pixel = 255 * sRGBToLinear(pixel / 255);
    return pixels;
}

std::vector<float> &sRGBColorSpace::fromLinearRGB(std::vector<float>& pixels)
{
    for (float & pixel : pixels)
        pixel = 255 * linearTosRGB(pixel / 255);
    return pixels;
}

float sRGBColorSpace::sRGBToLinear(float value) {
    if (value <= 0.04045)
        return value / 12.92;

    return std::pow(((value + 0.055) / 1.055), 2.4);
}

float sRGBColorSpace::linearTosRGB(float value) {
    if (value <= 0.0031308)
        return value * 12.92;

    return 1.055 * std::pow(value, 1 / 2.4) - 0.055;
}
