//
// Created by kotyangensss on 17.11.2022.
//

#include "GammaCorrection.h"

#include <cmath>

std::vector<float>&GammaCorrection::changeGamma(std::vector<float>& pixels, float& oldGamma, float& newGamma){
    auto *newPixels = new std::vector<float>(pixels.size(), 0);
    for (int i = 0; i < pixels.size(); i++){
        float &pixel = newPixels->at(i);
        pixel = std::pow(std::pow(pixels[i]/255, 1/oldGamma), newGamma) * 255;
    }
    return *newPixels;
}

