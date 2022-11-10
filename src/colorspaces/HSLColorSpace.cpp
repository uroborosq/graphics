//
// Created by UroborosQ on 03.11.2022.
//

#include "../../include/colorspaces/HSLColorSpace.h"
#include "cmath"

std::vector<float>& HSLColorSpace::to_rgb(std::vector<float> &pixels) {
    for (std::size_t i = 0; i < pixels.size(); i += 3)
    {
        auto h = pixels[i];
        auto s = pixels[i + 1];
        auto l = pixels[i + 2];

        h = h / 255.0 * 360.0;
        s /= 255.0;
        l /= 255.0;

        float q;
        if (l < 0.5)
            q = l * (1.0 + s);
        else
            q = l + s - l * s;

        float p = 2.0 * l - q;

        float h_k = h / 360.0;

        float t_c[3]{h_k + float(1.0 / 3.0), h_k, h_k - float(1.0 / 3.0)};

        for (float & j : t_c) {
            if (j < 0)
                j++;
            else if (j > 1)
                j--;

            if (j < 1.0 / 6.0)
                j = p + ((q - p) * 6.0 * j);
            else if (1.0 / 6.0 <= j and j < 1.0 / 2.0)
                j = q;
            else if (1.0 / 2.0 <= j and j < 2.0 / 3.0)
                j = p + ((q - p) * (2.0 / 3.0 - j) * 6.0);
            else
                j = p;
        }

        for (int j = 0; j < 3; j++)
        {
            pixels[i + j] = 255 * t_c[j];
        }
    }

    return pixels;
}

std::vector<float>& HSLColorSpace::from_rgb(std::vector<float> &pixels) {
    for (std::size_t i = 0; i < pixels.size(); i += 3)
    {
        float max = 0;
        float min = 255.0;
        for (auto j = i; j < i + 3; j++) {
            pixels[j] /= 255.0;
            if (max < pixels[j])
                max = pixels[j];
            if (min > pixels[j])
                min = pixels[j];
        }

        float h, s, l;

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

        l = (max + min) / 2;
        s = max == min ? 0 : (max - min) /(1 - std::abs(2*l - 1));

        pixels[i] = h * 255.0 / 360.0;
        pixels[i + 1] = s * 255.0;
        pixels[i + 2] = l * 255.0;
    }
    return pixels;
}
