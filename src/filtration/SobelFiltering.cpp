//
// Created by kotyangensss on 17.12.2022.
//

#include "SobelFiltering.h"
#include <cmath>

float calculateSobel(std::vector<float> &pixels, int width, int height, int x, int y, int colorSize, int curColor) {
    std::vector<int> gradY = {1, 2, 1, 0, 0, 0, -1, -2, -1};
    std::vector<int> gradX = {-1, 0, 1, -2, 0, 2, -1, 0, 1};
    float gx = 0;
    float gy = 0;
    for (int i = y - 1; i <= y + 1; i++) {
        for (int j = x - 1; j <= x + 1; j++) {
            if ((i < 0 || i >= height) && (j < 0 || j >= width)) {
                gy += pixels.at((y * width + x) * colorSize + curColor) * gradY[3 * (i - y + 1) + j + 1 - x];
                gx += pixels.at((y * width + x) * colorSize + curColor) * gradX[3 * (i - y + 1) + j + 1 - x];
            }
            else if (i < 0 || i >= height) {
                gy += pixels.at((y * width + j) * colorSize + curColor) * gradY[3 * (i - y + 1) + j + 1 - x];
                gx += pixels.at((y * width + j) * colorSize + curColor) * gradX[3 * (i - y + 1) + j + 1 - x];
            } else if (j < 0 || j >= width) {
                gy += pixels.at((i * width + x) * colorSize + curColor) * gradY[3 * (i - y + 1) + j + 1 - x];
                gx += pixels.at((i * width + x) * colorSize + curColor) * gradX[3 * (i - y + 1) + j + 1 - x];
            } else {
                gy += pixels.at((i * width + j) * colorSize + curColor) * gradY[3 * (i - y + 1) + j + 1 - x];
                gx += pixels.at((i * width + j) * colorSize + curColor) * gradX[3 * (i - y + 1) + j + 1 - x];
            }
        }
    }

    return std::sqrt(std::pow(gx,2) + std::pow(gy, 2));
}


std::vector<float> &SobelFiltering::filter(std::vector<float> &pixels, int width, int height) {
    int colorSize = pixels.size() / (width * height);
    auto *newPixels = new std::vector<float>(pixels.size(), 0);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            for (int k = 0; k < colorSize; k++) {
                newPixels->at((i * width + j) * colorSize + k) = calculateSobel(pixels, width, height, j, i,
                                                                                colorSize, k);
            }
        }
    }

    return *newPixels;
}