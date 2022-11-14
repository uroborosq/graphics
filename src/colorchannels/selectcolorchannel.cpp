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

std::vector<float>* remove_other_channels(const std::vector<float>& pixels, const ColorChannel& colorChannel)
{
    auto* filtered_pixels = new std::vector<float>();
    if (colorChannel == ColorChannel::Все)
    {
        for (float pixel : pixels)
        {
            filtered_pixels->push_back(pixel);
        }
        return filtered_pixels;
    }

    for (std::size_t i = colorChannel - 1; i < filtered_pixels->size(); i += 3)
    {
        for (float pixel : pixels)
        {
            filtered_pixels->push_back(pixel);
        }
        return filtered_pixels;
    }

    return filtered_pixels;
}
