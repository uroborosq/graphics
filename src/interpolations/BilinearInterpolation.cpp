//
// Created by kotyangensss on 15.12.2022.
//

#include <cmath>
#include "BilinearInterpolation.h"

float setColor(
        float c11,
        float c12,
        float c21,
        float c22,
        float x,
        float y
        ) {
    auto *pixel = new float(c11 + x * (c12 - c11) + y * (c21 + x * (c22 - c21) - (c11 + x * (c12 - c11))));
    return *pixel;
}

std::vector<float> &BilinearInterpolation::interpolate(
        std::vector<float> &pixels,
        int width,
        int height,
        int newWidth,
        int newHeight,
        float x,
        float y,
        double b,
        double c
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
                    newPixels->at((width * i + j) * colorSize + k) = setColor(
                            pixels[(((centerY + y - newHeight / 2) + std::floor(gradY * i)) * width +
                                    (centerX + x - newWidth / 2) + std::floor(gradX * j)) * colorSize + k],
                            pixels[(((centerY + y - newHeight / 2) + std::floor(gradY * i)) * width +
                                    (centerX + x - newWidth / 2) + std::ceil(gradX * j)) * colorSize + k],
                            pixels[(((centerY + y - newHeight / 2) + std::ceil(gradY * i)) * width +
                                    (centerX + x - newWidth / 2) + std::floor(gradX * j)) * colorSize + k],
                            pixels[(((centerY + y - newHeight / 2) + std::ceil(gradY * i)) * width +
                                    (centerX + x - newWidth / 2) + std::ceil(gradX * j)) * colorSize + k],
                            (gradX * j) - floor(gradX * j), (gradY * i) - std::floor(gradY * i)
                    );
                }
            }
        }
    }
    return *newPixels;
}
