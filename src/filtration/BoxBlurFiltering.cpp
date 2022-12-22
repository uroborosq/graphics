//
// Created by kotyangensss on 17.12.2022.
//

#include <cmath>
#include "BoxBlurFiltering.h"

float calculateBoxBlur(std::vector<float> &pixels, int width, int height, int x, int y, int colorSize, int curColor, int radius) {
    float ans = 0;
    int num = 0;
    for (int i = y - radius; i <= y +radius; i++) {
        for (int j = x - radius; j <= x + radius; j++) {
            if (i < 0 || i >= height || j < 0 || j >= width) {
                continue;
            }
            ans += pixels.at((i * width + j) * colorSize + curColor);
            num++;
        }
    }
    return ans / num;
}

std::vector<float> &BoxBlurFiltering::filter(std::vector<float> &pixels, FilterConfiguration config, int width,
                                             int height) {
    int colorSize = pixels.size() / (width * height);
    auto *newPixels = new std::vector<float>(pixels.size(), 0);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            for (int k = 0; k < colorSize; k++) {
                newPixels->at((i * width + j) * colorSize + k) = calculateBoxBlur(pixels, width, height, j, i,
                                                                                  colorSize, k, config.radius);
            }
        }
    }

    return *newPixels;
}