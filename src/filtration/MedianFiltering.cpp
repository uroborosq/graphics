//
// Created by kotyangensss on 17.12.2022.
//

#include <cmath>
#include <algorithm>
#include "MedianFiltering.h"


float calculateMedian(std::vector<float> &pixels, int width, int height, int x, int y, int colorSize, int curColor, int radius) {
    auto *window = new std::vector<float>();
    for (int i = y - radius; i <= y + radius; i++) {
        for (int j = x - radius; j <= x + radius; j++) {
            if (i < 0 || i >= height || j < 0 || j >= width) {
                continue;
            }
            window->push_back(pixels.at((i * width + j) * colorSize + curColor));
        }
    }
    sort(window->begin(), window->end());
    return window->at(window->size() / 2);
}


std::vector<float> &MedianFiltering::filter(std::vector<float> &pixels, FilterConfiguration config, int width,
                                            int height) {
    int colorSize = pixels.size() / (width * height);
    auto *newPixels = new std::vector<float>(pixels.size(), 0);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            for (int k = 0; k < colorSize; k++) {
                newPixels->at((i * width + j) * colorSize + k) = calculateMedian(pixels, width, height, j, i,
                                                                                  colorSize, k, config.radius);
            }
        }
    }

    return *newPixels;
}