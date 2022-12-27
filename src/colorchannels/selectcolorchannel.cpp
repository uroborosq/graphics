//
// Created by uroborosq on 05.11.22.
//
#include "selectcolorchannel.h"

std::vector<float> select_color_channel(const std::vector<float> &pixels, const ColorChannel &colorChannel) {
    auto size = pixels.size();
    if (colorChannel == ColorChannel::All) {
        return pixels;
    }
   auto filtered_pixels = std::vector<float>(size);
   for (std::size_t i = colorChannel - 1; i < size; i += 3)
   {
//       if (i % 3 != colorChannel - 1)
//           pixels[i] = 0;
       filtered_pixels[i] = pixels[i];
   }

    return filtered_pixels;
}

std::vector<float> remove_other_channels(const std::vector<float> &pixels, const ColorChannel &colorChannel) {
    auto size = pixels.size();
    if (colorChannel == ColorChannel::All) {
        return pixels;
    }
    auto filtered_pixels = std::vector<float>();

    for (std::size_t i = colorChannel - 1; i < size; i += 3) {
        filtered_pixels.push_back(pixels[i]);
    }

    return filtered_pixels;
}
