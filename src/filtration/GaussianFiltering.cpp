//
// Created by kotyangensss on 17.12.2022.
//

#include "GaussianFiltering.h"
#include <cmath>

float GaussianFiltering::sigma = 1;

float calculateGauss(std::vector<float> &pixels, std::vector<float> &gauss, int width, int height, int x, int y,
                     int colorSize, int curColor) {
    float ans = 0;
    for (int i = y - 3 * std::floor(GaussianFiltering::sigma); i <= y + 3 * std::floor(GaussianFiltering::sigma); i++) {
        for (int j = x - 3 * std::floor(GaussianFiltering::sigma); j <= x + 3 * std::floor(GaussianFiltering::sigma); j++) {
            if (i < 0 || i >= height || j < 0 || j >= width) {
                ans += pixels.at((y * width + x) * colorSize + curColor)
                       * gauss.at(
                        (i - y + 3 *  std::floor(GaussianFiltering::sigma)) * (6 * std::floor(GaussianFiltering::sigma) + 1) + j - x +
                        3 * std::floor(GaussianFiltering::sigma));
            } else {
                ans += pixels.at((i * width + j) * colorSize + curColor)
                       * gauss.at(
                        (i - y + 3 *  std::floor(GaussianFiltering::sigma)) * (6 * std::floor(GaussianFiltering::sigma) + 1) + j - x +
                                3 * std::floor(GaussianFiltering::sigma));
            }
        }
    }
    return ans;
}

std::vector<float> &GaussianFiltering::filter(std::vector<float> &pixels, int width, int height) {
    int colorSize = pixels.size() / (width * height);
    auto *newPixels = new std::vector<float>(pixels.size(), 0);
    auto *gauss = new std::vector<float>(std::pow(6 * std::floor(sigma) + 1, 2), 0);
    float gaussSum = 0;
    for (int i = 0; i <= 6 * std::floor(sigma); i++) {
        for (int j = 0; j <= 6 * std::floor(sigma); j++) {
            float t = std::pow(M_E, -(std::pow(i - 3 * std::floor(sigma), 2) + (std::pow(j - 3 * std::floor(sigma), 2)) / (2 * sigma * sigma))) / (2 * M_PI * sigma * sigma);
            gauss->at(i * (6 * std::floor(sigma) + 1) + j) = t;
            gaussSum += t;
        }
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            for (int k = 0; k < colorSize; k++) {
                newPixels->at((i * width + j) * colorSize + k) = calculateGauss(pixels, *gauss, width, height, j, i,
                                                                                colorSize, k) / gaussSum;
            }
        }
    }

    return *newPixels;
}