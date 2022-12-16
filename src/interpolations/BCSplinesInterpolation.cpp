//
// Created by kotyangensss on 15.12.2022.
//
#include <cmath>
#include "BCSplinesInterpolation.h"

float BCSplinesInterpolation::b = 0.0;
float BCSplinesInterpolation::c = 0.5;

float bc(float x) {
    if (std::abs(x) < 1) {
        return ((12 - 9 * BCSplinesInterpolation::b - 6 * BCSplinesInterpolation::c) * pow(std::abs(x), 3)
                + (-18 + 12 * BCSplinesInterpolation::b + 6 * BCSplinesInterpolation::c) * pow(std::abs(x), 2)
                + (6 - 2 * BCSplinesInterpolation::b)) / 6;
    } else if (std::abs(x) < 2) {
        return ((-1 * BCSplinesInterpolation::b - 6 * BCSplinesInterpolation::c) * pow(std::abs(x), 3)
                + (6 * BCSplinesInterpolation::b + 30 * BCSplinesInterpolation::c) * pow(std::abs(x), 2)
                + (-12 * BCSplinesInterpolation::b - 48 * BCSplinesInterpolation::c) * std::abs(x)
                + (8 * BCSplinesInterpolation::b + 24 * BCSplinesInterpolation::c)) / 6;
    } else {
        return 0;
    }
}

float calculateBC(
        std::vector<float> &pixels,
        int width,
        int height,
        int colorSize,
        int curColor,
        float x,
        float y
) {
    float ans = 0;
    for (int i = -1; i <= 2; i++) {
        for (int j = -1; j <= 2; j++) {
            if (std::floor(y) + j < 0
                || std::floor(y) + j >= height
                || std::floor(x) + i < 0
                || std::floor(x) + i >= width
                    ) {
                continue;
            }
            ans += pixels[((std::floor(y) + j) * width + std::floor(x) + i) * colorSize + curColor]
                   * bc(i - x + std::floor(x))
                   * bc(j - y + std::floor(y));
        }
    }
    return std::abs(ans) > 255 ? 255 : std::abs(ans);
}

std::vector<float> &BCSplinesInterpolation::interpolate(
        std::vector<float> &pixels,
        int width,
        int height,
        int newWidth,
        int newHeight,
        float x,
        float y
) {
    int centerX = width / 2;
    int centerY = height / 2;
    int colorSize = pixels.size() / (width * height);
    float gradX = (float) (newWidth - 1) / (float) (width - 1);
    float gradY = (float) (newHeight - 1) / (float) (height - 1);
    auto *newPixels = new std::vector<float>(pixels.size(), 0);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            for (int k = 0; k < colorSize; k++) {
                if (((centerY + y - newHeight / 2) + std::floor(gradY * i)) < 0
                    || ((centerY + y - newHeight / 2) + std::ceil(gradY * i)) >= height
                    || (centerX + x - newWidth / 2) + std::floor(gradX * j) < 0
                    || (centerX + x - newWidth / 2) + std::ceil(gradX * j) >= width
                        ) {
                    newPixels->at((width * i + j) * colorSize + k) = 0;
                } else {
                    newPixels->at((width * i + j) * colorSize + k) = calculateBC(
                            pixels,
                            width,
                            height,
                            colorSize,
                            k,
                            (centerX + x - newWidth / 2) + gradX * j,
                            (centerY + y - newHeight / 2) + gradY * i
                    );
                }
            }
        }
    }
    return *newPixels;
}
