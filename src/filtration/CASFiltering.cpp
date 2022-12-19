//
// Created by kotyangensss on 17.12.2022.
//

#include <cmath>
#include "CASFiltering.h"
#include "FilterConfiguration.h"

float calculateSharpening(std::vector<float> &pixels, int width, int height, int x, int y, int colorSize, int curColor, float sharpness) {
    float minG = 255;
    float maxG = 0;
    for (int j = -1; j <= 1; j++) {
        if (x + j < 0 || x + j >= width || y + j < 0 || y + j >= height) {
            continue;
        }

        if (pixels.at((y * width + x + j) * colorSize + curColor) < minG) {
            minG = pixels.at((y * width + x + j) * colorSize + curColor);
        }

        if (pixels.at((y * width + x + j) * colorSize + curColor) > maxG) {
            maxG = pixels.at((y * width + x + j) * colorSize + curColor);
        }

        if (pixels.at(((y + j) * width + x) * colorSize + curColor) < minG) {
            minG = pixels.at(((y + j) * width + x) * colorSize + curColor);
        }

        if (pixels.at(((y + j) * width + x) * colorSize + curColor) > maxG) {
            maxG = pixels.at(((y + j) * width + x) * colorSize + curColor);
        }
    }

    float dMinG = minG;
    float dMaxG = 255 - maxG;
    float w;
    if (dMaxG < dMinG) {
        w = std::sqrt(dMaxG / maxG) * (-0.075 * sharpness - 0.125);
    } else {
        w = std::sqrt(dMinG / maxG) * (-0.075 * sharpness - 0.125);
    }
    float ans = 0;
    float num = 0;

    ans += pixels.at((y * width + x) * colorSize + curColor);
    num++;
    if (x - 1 >= 0) {
        ans += pixels.at((y * width + x - 1) * colorSize + curColor) * w;
        num += w;
    }
    if (x + 1 < width) {
        ans += pixels.at((y * width + x + 1) * colorSize + curColor) * w;
        num += w;
    }
    if (y - 1 >= 0) {
        ans += pixels.at(((y - 1) * width + x) * colorSize + curColor) * w;
        num += w;
    }
    if (y + 1 < height) {
        ans += pixels.at(((y + 1) * width + x) * colorSize + curColor) * w;
        num += w;
    }

    ans /= num;
    if (ans < 0) {
        return 0;
    } else if (ans > 255) {
        return 255;
    } else {
        return ans;
    }
}

std::vector<float> &CASFiltering::filter(std::vector<float> &pixels, FilterConfiguration config, int width,
                                         int height) {
    int colorSize = pixels.size() / (width * height);
    auto *newPixels = new std::vector<float>(pixels.size(), 0);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            for (int k = 0; k < colorSize; k++) {
                newPixels->at((i * width + j) * colorSize + k) = calculateSharpening(pixels, width, height, j, i,
                                                                                     colorSize, k, config.sharpness);
            }
        }
    }

    return *newPixels;
}
