//
// Created by uroborosq on 05.11.22.
//
#include "selectcolorchannel.h"

std::vector<float> *select_color_channel(const std::vector<float> &pixels, const ColorChannel &colorChannel) {
    auto size = pixels.size();
    auto *filtered_pixels = new std::vector<float>(size, 0);
    if (colorChannel == ColorChannel::All) {
        for (std::size_t i = 0; i < size; i++) {
            float &pixel = filtered_pixels->at(i);
            pixel = pixels[i];
        }
        return filtered_pixels;
    }

    for (std::size_t i = colorChannel - 1; i < size; i += 3) {
        float &pixel = filtered_pixels->at(i);
        pixel = pixels[i];
    }

    return filtered_pixels;
}

std::vector<float> *remove_other_channels(const std::vector<float> &pixels, const ColorChannel &colorChannel) {
    auto *filtered_pixels = new std::vector<float>();
    if (colorChannel == ColorChannel::All) {
        for (float pixel: pixels) {
            filtered_pixels->push_back(pixel);
        }
        return filtered_pixels;
    }
    auto size = pixels.size();
    for (std::size_t i = colorChannel - 1; i < size; i += 3) {
        filtered_pixels->push_back(pixels[i]);
    }

    return filtered_pixels;
}
