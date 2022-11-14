//
// Created by uroborosq on 05.11.22.
//
#include "selectcolorchannel.h"

std::vector<float>* select_color_channel(const std::vector<float>& pixels, const ColorChannel& colorChannel)
{
    auto* filtered_pixels = new std::vector<float>(pixels.size(), 0);
    if (colorChannel == ColorChannel::Все)
    {
        for (std::size_t i = 0; i < pixels.size(); i++)
        {
            float & pixel = filtered_pixels->at(i);
            pixel = pixels[i];
        }
        return filtered_pixels;
    }

    for (std::size_t i = colorChannel - 1; i < filtered_pixels->size(); i += 3)
    {
        float & pixel = filtered_pixels->at(i);
        pixel = pixels[i];
    }

    return filtered_pixels;
}
