#define _USE_MATH_DEFINES
#include <cmath>
#include "LanczosInterpolation.h"

double lanczosFilter(float x, int a) {
    if (x < 0.00000001) {
        return 1;
    } else if (std::abs(x) < a) {
        return (sin(M_PI * x) * sin(M_PI * x / a)) / ((M_PI * x) * (M_PI * x)) * a;
    } else {
        return 0;
    }
}

float calculateLanczos(
        std::vector<float> &pixels,
        int width,
        int height,
        int colorSize,
        int curColor,
        float x,
        float y
) {
    float ans = 0;
    float w = 0;
    for (int i = -2; i <= 3; i++) {
        for (int j = -2; j <= 3; j++) {
            if (std::floor(y) + j < 0
                || std::floor(y) + j >= height
                || std::floor(x) + i < 0
                || std::floor(x) + i >= width
                    ) {
                continue;
            }
            float t = lanczosFilter(i - x + std::floor(x), 3)
                      * lanczosFilter(j - y + std::floor(y), 3);
            ans += pixels[((std::floor(y) + j) * width + std::floor(x) + i) * colorSize + curColor] * t;
            w += t;
        }
    }
    return std::abs(ans / w);
}

std::vector<float> &LanczosInterpolation::interpolate(
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
                    newPixels->at((width * i + j) * colorSize + k) = calculateLanczos(
                            pixels,
                            width,
                            height,
                            colorSize,
                            k,
                            (centerX + x - newWidth / 2) + gradX * j,
                            (centerY + y - newHeight / 2) + gradY * i);
                }
            }
        }
    }
    return *newPixels;
}