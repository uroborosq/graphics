//
// Created by uroborosq on 05.11.22.
//
#include "selectcolorchannel.h"

std::vector<float>& select_color_channel(std::vector<float> &pixels, const ColorChannel &colorChannel) {
    auto size = pixels.size();
    if (colorChannel == ColorChannel::All) {
        return pixels;
    }

   for (std::size_t i = 0; i < size; i++)
   {
       if (i % 3 != colorChannel - 1)
           pixels[i] = 0;
   }

    return pixels;
}

std::vector<float>& remove_other_channels(const std::vector<float> &pixels, const ColorChannel &colorChannel) {
    auto size = pixels.size();
    auto* filtered_pixels = new std::vector<float>(size);
    if (colorChannel == ColorChannel::All) {
        for (float pixel: pixels) {
            filtered_pixels->push_back(pixel);
        }
        return *filtered_pixels;
    }
    for (std::size_t i = colorChannel - 1; i < size; i += 3) {
        filtered_pixels->push_back(pixels[i]);
    }

    return *filtered_pixels;
}
