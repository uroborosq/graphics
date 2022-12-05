//
// Created by kotyangensss on 06.11.2022.
//

#include "YCbCr_601ColorSpace.h"
#include <cmath>

std::vector<float> &YCbCr_601ColorSpace::toLinearRGB(std::vector<float> &pixels){
    auto size = pixels.size();
    for (std::size_t i = 0; i < size; i += 3)
    {
        float y = pixels[i];
        float cb = pixels[i + 1];
        float cr = pixels[i + 2];

        pixels[i] = y + 1.4022 * cr;
        pixels[i + 1] = y - 0.3456 * cb - 0.7145 * cr;
        pixels[i + 2] = y + 1.7710 * cb;
    }
    return pixels;
}

std::vector<float> &YCbCr_601ColorSpace::fromLinearRGB(std::vector<float> &pixels){
    auto size = pixels.size();
    for (std::size_t i = 0; i < size; i += 3)
    {
        float r = pixels[i];
        float g = pixels[i + 1];
        float b = pixels[i + 2];

        pixels[i] = 0.2989 * r + 0.5866 * g + 0.1145 * b;
        pixels[i + 1] = -0.1687 * r - 0.3313 * g + 0.5 * b;
        pixels[i + 2] = 0.5 * r - 0.4184 * g - 0.0816 * b;
    }
    return pixels;
}

