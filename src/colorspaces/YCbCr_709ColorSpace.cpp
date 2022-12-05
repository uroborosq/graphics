//
// Created by kotyangensss on 06.11.2022.
//

#include "YCbCr_709ColorSpace.h"
#include <cmath>

std::vector<float> &YCbCr_709ColorSpace::toLinearRGB(std::vector<float> &pixels){
    auto size = pixels.size();
    for (std::size_t i = 0; i < size; i += 3)
    {
        float y = pixels[i];
        float cb = pixels[i + 1];
        float cr = pixels[i + 2];

        pixels[i] = y + 1.5748 * cr;
        pixels[i + 1] = y - 0.1873 * cb - 0.4681 * cr;
        pixels[i + 2] = y + 1.8556 * cb;
    }
    return pixels;
}

std::vector<float> &YCbCr_709ColorSpace::fromLinearRGB(std::vector<float> &pixels){
    auto size = pixels.size();
    for (std::size_t i = 0; i < size; i += 3)
    {
        float r = pixels[i];
        float g = pixels[i + 1];
        float b = pixels[i + 2];

        pixels[i] = 0.2126 * r + 0.7152 * g + 0.0722 * b;
        pixels[i + 1] = -0.1146 * r - 0.3854 * g + 0.5 * b;
        pixels[i + 2] = 0.5 * r - 0.4542 * g - 0.0458 * b;
    }
    return pixels;
}