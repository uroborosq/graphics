//
// Created by kotyangensss on 17.12.2022.
//

#include "ThresholdFiltering.h"
#include "FilterConfiguration.h"


std::vector<float> &ThresholdFiltering::filter(std::vector<float> &pixels, FilterConfiguration config, int width,
                                               int height) {
    for (float & pixel : pixels) {
        if (config.isUpper) {
            pixel = pixel >= config.threshold ? 0 : 255;
        } else {
            pixel = pixel <= config.threshold ? 0 : 255;
        }
    }

    return pixels;
}