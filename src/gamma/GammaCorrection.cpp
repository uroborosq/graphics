//
// Created by kotyangensss on 17.11.2022.
//

#include "GammaCorrection.h"

#include <cmath>

std::vector<float> &GammaCorrection::changeGamma(std::vector<float> &pixels, const float &oldGamma,const float &newGamma) {
    if (oldGamma == 0 or newGamma == 0)
        exit(228);
    auto *newPixels = new std::vector<float>(pixels.size(), 0);
    auto size = pixels.size();
    for (int i = 0; i < size; i++) {
        float &pixel = newPixels->at(i);
        pixel = std::pow(std::pow(pixels[i] / 255, 1 / oldGamma), newGamma) * 255;
    }
    return *newPixels;
}

