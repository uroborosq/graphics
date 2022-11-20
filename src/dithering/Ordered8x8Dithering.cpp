//
// Created by uroborosq on 20.11.22.
//
#include <cmath>
#include "Ordered8x8Dithering.h"

std::vector<float> &Ordered8x8Dithering::proceed(std::vector<float> &pixels, int width, int height) {
    auto size = pixels.size();
    for (std::size_t i = 0; i < size; i++){
            auto x = i / width / 3;
            auto y = i % (width * 3 );
            auto element = thresholdMatrix[(x % 8) * 8 + (y % 8)];
            element = 255.0 / 64.0 * (element+1)  - 0.5;
            auto newColor = int(std::round(pixels[i] + element));
            pixels[i] = newColor >= 0 ? newColor % 255 : 0;
            auto lol = pixels[i];
        }
    return pixels;
}