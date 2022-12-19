//
// Created by kotyangensss on 17.12.2022.
//

#include "ThresholdFiltering.h"

float ThresholdFiltering::threshold = 0;
bool ThresholdFiltering::isUpper = false;

std::vector<float> &ThresholdFiltering::filter(std::vector<float>& pixels, int width, int height) {
    for (float & pixel : pixels) {
        if (isUpper) {
            pixel = pixel >= threshold ? 0 : 255;
        } else {
            pixel = pixel <= threshold ? 0 : 255;
        }
    }

    return pixels;
}