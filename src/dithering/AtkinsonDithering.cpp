//
// Created by uroborosq on 21.11.22.
//

#include "AtkinsonDithering.h"
#include "BordersController.h"
#include "NearestColor.h"

std::vector<float> &AtkinsonDithering::proceed(std::vector<float> &pixels, int width, int depth, bool isColorful) {
    auto numberOfColorChannels = isColorful ? 3 : 1;

    auto height = pixels.size() / width / numberOfColorChannels;
    for (std::size_t i = 0; i < height ; i++)
        for (std::size_t j = 0; j < width; j++)
            for (int color = 0; color < numberOfColorChannels; color++)
            {
                auto offset = i * width * numberOfColorChannels + j * numberOfColorChannels + color;
                float newColor = nearestColor(depth, checkBorders(pixels[offset]));
                if (pixels[offset] < 0)
                    auto a = 1;
                auto error = pixels[offset] - newColor;
                pixels[offset] = newColor;
                if (j + 1 < width) {
                    pixels[(i) * width * numberOfColorChannels + (j + 1) * numberOfColorChannels + color] += error / 8.0;
                    if (i + 1 < height) {
                        pixels[(i + 1) * width * numberOfColorChannels + (j + 1) * numberOfColorChannels + color] += error / 8.0;
                    }
                }
                if (i + 1 < height) {
                    pixels[(i + 1) * width * numberOfColorChannels + (j) * numberOfColorChannels + color] += error / 8.0;
                    if (j > 0)
                        pixels[(i + 1) * width * numberOfColorChannels + (j - 1) * numberOfColorChannels + color] += error / 8.0;

                }
                if (j + 2 < width) {
                    pixels[(i) * width * numberOfColorChannels + (j + 2) * numberOfColorChannels + color] += error / 8.0;
                }
                if (i + 2 < height) {
                    pixels[(i + 2) * width * numberOfColorChannels + (j) * numberOfColorChannels + color] += error / 8.0;
                }

            }

    return pixels;
}
