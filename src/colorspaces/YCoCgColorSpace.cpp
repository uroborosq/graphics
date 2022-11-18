//
// Created by kotyangensss on 06.11.2022.
//

#include "YCoCgColorSpace.h"
#include <cmath>

std::vector<float> &YCoCgColorSpace::to_rgb(std::vector<float> &pixels){
    auto size = pixels.size();
    for (std::size_t i = 0; i < size; i += 3)
    {
        float y = pixels[i];
        float co = pixels[i + 1];
        float cg = pixels[i + 2];

        pixels[i] = y + co - cg;
        pixels[i + 1] = y + cg;
        pixels[i + 2] = y - co - cg;
    }
    return pixels;
}

std::vector<float> &YCoCgColorSpace::from_rgb(std::vector<float> &pixels){
    auto size = pixels.size();
    for (std::size_t i = 0; i < size; i += 3)
    {
        float r = pixels[i];
        float g = pixels[i + 1];
        float b = pixels[i + 2];

        pixels[i] = 0.25 * r + 0.5 * g + 0.25 * b;
        pixels[i + 1] = 0.5 * r - 0.5 * b;
        pixels[i + 2] = -0.25 * r + 0.5 * g - 0.25 * b;
    }
    return pixels;
}