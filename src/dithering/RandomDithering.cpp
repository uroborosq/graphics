//
// Created by uroborosq on 21.11.22.
//

#include <cstdlib>
#include "RandomDithering.h"
#include "NearestColor.h"

std::vector<float> &RandomDithering::proceed(std::vector<float> &pixels, int width, int depth, bool isColorful) {
    auto size = pixels.size();
    for (std::size_t i = 0; i < size; i++) {
        float newColor = pixels[i] + std::rand() % 256 - 128;
        pixels[i] = nearestColor(depth, newColor >= 0 ? newColor > 255 ? 255 : newColor : 0);
    }
    return pixels;
}
