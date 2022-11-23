//
// Created by uroborosq on 20.11.22.
//
#include <cmath>
#include "Ordered8x8Dithering.h"
#include "NearestColor.h"


std::vector<float> &Ordered8x8Dithering::proceed(std::vector<float> &pixels, int width, int depth, bool isColorful) {
    auto size = pixels.size();
    for (std::size_t i = 0; i < size; i++) {
        float newColor = std::round(
                (pixels[i] / 255.0 + thresholdMatrix[(i / width / (isColorful ? 3 : 1)) % 8][(i % (width * (isColorful ? 3 : 1))) % 8] / 64.0 - 0.5) * 255);
        pixels[i] = nearestColor(depth, newColor >= 0 ? newColor > 255 ? 255 : newColor : 0);
    }
    return pixels;
}


