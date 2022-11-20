//
// Created by uroborosq on 20.11.22.
//
#include <cmath>
#include "Ordered8x8Dithering.h"

const std::vector<float> &Ordered8x8Dithering::proceed(std::vector<float> &pixels, int width, int height) {
    for (std::size_t i = 0; i < height; i++)
        for (std::size_t j = 0; j < width; j++) {
            auto offset = i * width * 3 + j * 3;
            pixels[offset] = std::round(pixels[offset] + 255.0 / 64.0 * (thresholdMatrix[(j % 8) * 8 + (i % 8)] - 0.5));
        }
    return pixels;
}
