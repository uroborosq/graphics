//
// Created by uroborosq on 05.11.22.
//
#include "CMYColorSpace.h"

std::vector<float> &CMYColorSpace::to_rgb(std::vector<float> &pixels) {
    for (float &pixel: pixels) {
        pixel = 255.0 - pixel;
    }
    return pixels;
}

std::vector<float> &CMYColorSpace::from_rgb(std::vector<float> &pixels) {
    return to_rgb(pixels);
}
