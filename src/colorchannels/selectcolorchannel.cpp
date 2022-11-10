//
// Created by uroborosq on 05.11.22.
//
#include "selectcolorchannel.h"
std::vector<float>* select_color_channel(const std::vector<float>& pixels, int color_channel)
{
    auto* filtered_pixels = new std::vector<float>(pixels.size(), 0);
    for (std::size_t i = color_channel; i < filtered_pixels->size(); i += 3)
    {
        float & pixel = filtered_pixels->at(i);
        pixel = pixels[i];
    }

    return filtered_pixels;
}
