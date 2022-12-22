//
// Created by kotyangensss on 15.12.2022.
//

#include "NearestNeighbourInterpolation.h"
#include <cmath>

std::vector<float> &NearestNeighbourInterpolation::interpolate(
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
    float gradX = (float) newWidth / (float) width;
    float gradY = (float) newHeight / (float) height;
    auto *newPixels = new std::vector<float>(pixels.size(), 0);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            for (int k = 0; k < colorSize; k++) {
                if (((centerY + y - newHeight / 2) + std::floor(gradY * i)) < 0
                    || ((centerY + y - newHeight / 2) + std::floor(gradY * i)) >= height
                    || (centerX + x - newWidth / 2) + std::floor(gradX * j) < 0
                    || (centerX + x - newWidth / 2) + std::floor(gradX * j) >= width
                        ) {
                    newPixels->at((width * i + j) * colorSize + k) = 0;
                } else {
                    newPixels->at((width * i + j) * colorSize + k) =
                            pixels[(((centerY + y - newHeight / 2) + std::floor(gradY * i)) * width +
                                    (centerX + x - newWidth / 2) + std::floor(gradX * j)) * colorSize + k];
                }
            }
        }
    }
    return *newPixels;
}