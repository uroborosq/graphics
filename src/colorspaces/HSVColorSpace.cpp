//
// Created by uroborosq on 04.11.22.
//

#include "HSVColorSpace.h"
#include <cmath>

std::vector<float> &HSVColorSpace::toLinearRGB(std::vector<float> &pixels) {
    auto size = pixels.size();
    for (std::size_t i = 0; i < size; i += 3) {
        auto h = pixels[i];
        auto s = pixels[i + 1];
        auto v = pixels[i + 2];

        h = h / 255.0 * 360.0;
        s /= 255.0;
        v /= 255.0;

        float c = v * s;
        float x = c * (1.0 - std::abs(std::fmod(h / 60.0, 2.0) - 1));
        float m = v - c;

        // самый лучший код в мире
        if (h < 60.0)
            assign_pixels(i, pixels, c, x, 0);
        else if (60.0 <= h and h < 120.0)
            assign_pixels(i, pixels, x, c, 0);
        else if (120.0 <= h and h < 180.0)
            assign_pixels(i, pixels, 0, c, x);
        else if (180.0 <= h and h < 240.0)
            assign_pixels(i, pixels, 0, x, c);
        else if (240.0 <= h and h < 300.0)
            assign_pixels(i, pixels, x, 0, c);
        else
            assign_pixels(i, pixels, c, 0, x);

        for (int j = 0; j < 3; j++)
            pixels[i + j] += m * 255.0;

    }
    return pixels;
}

std::vector<float> &HSVColorSpace::fromLinearRGB(std::vector<float> &pixels) {
    auto size = pixels.size();
    for (std::size_t i = 0; i < size; i += 3) {
        float max = 0;
        float min = 255.0;
        for (auto j = i; j < i + 3; j++) {
            pixels[j] /= 255.0;
            if (max < pixels[j])
                max = pixels[j];
            if (min > pixels[j])
                min = pixels[j];
        }

        float h, s, v;

        if (max == min)
            h = 0;
        else if (max == pixels[i] and pixels[i + 1] >= pixels[i + 2])
            h = 60.0 * ((pixels[i + 1] - pixels[i + 2]) / (max - min));
        else if (max == pixels[i] and pixels[i + 1] < pixels[i + 2])
            h = 60.0 * ((pixels[i + 1] - pixels[i + 2]) / (max - min) + 6);
        else if (max == pixels[i + 1])
            h = 60.0 * ((pixels[i + 2] - pixels[i]) / (max - min) + 2);
        else
            h = 60.0 * ((pixels[i] - pixels[i + 1]) / (max - min) + 4);

        v = max;
        s = max == min ? 0 : 1 - min / max;

        pixels[i] = h * 255.0 / 360.0;
        pixels[i + 1] = s * 255.0;
        pixels[i + 2] = v * 255.0;
    }
    return pixels;
}

void
HSVColorSpace::assign_pixels(std::size_t index, std::vector<float> &pixels, const float &first, const float &second,
                             const float &third) {
    pixels[index] = 255.0 * first;
    pixels[index + 1] = 255.0 * second;
    pixels[index + 2] = 255.0 * third;
}
