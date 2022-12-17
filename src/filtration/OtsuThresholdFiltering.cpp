//
// Created by kotyangensss on 17.12.2022.
//
#include "OtsuThresholdFiltering.h"
#include <cmath>

const int INTENSITY_LAYER_NUMBER = 256;

std::vector<float> &calculateHist(std::vector<float>& pixels) {
    auto *hist = new std::vector<float>(pixels.size(), 0);
    for (float pixel : pixels) {
        hist->at((int)std::floor(pixel)) += 1;
    }

    return *hist;
}

float calculateIntensitySum(std::vector<float>& pixels) {
    float sum = 0;
    for (float pixel : pixels) {
        sum += pixel;
    }

    return sum;
}

int otsuThreshold(std::vector<float>& pixels) {
    auto hist = calculateHist(pixels);
    float best_thresh = 0;
    float best_sigma = 0.0;
    int first_class_pixel_count = 0;
    int first_class_intensity_sum = 0;

    for (int thresh = 0; thresh < INTENSITY_LAYER_NUMBER - 1; ++thresh) {
        first_class_pixel_count += hist[thresh];
        first_class_intensity_sum += thresh * hist[thresh];

        double first_class_prob = first_class_pixel_count / (double) pixels.size();
        double second_class_prob = 1.0 - first_class_prob;

        double first_class_mean = first_class_intensity_sum / (double) first_class_pixel_count;
        double second_class_mean = (calculateIntensitySum(pixels) - first_class_intensity_sum)
                                   / (double) (pixels.size() - first_class_pixel_count);

        double mean_delta = first_class_mean - second_class_mean;

        double sigma = first_class_prob * second_class_prob * mean_delta * mean_delta;

        if (sigma > best_sigma) {
            best_sigma = sigma;
            best_thresh = thresh;
        }
    }

    return best_thresh;
}

bool OtsuThresholdFiltering::isUpper = false;

std::vector<float> &OtsuThresholdFiltering::filter(std::vector<float>& pixels) {
    float threshold = otsuThreshold(pixels);
    for (float & pixel : pixels) {
        if (isUpper) {
            pixel = pixel >= threshold ? 0 : 255;
        } else {
            pixel = pixel <= threshold ? 0 : 255;
        }
    }

    return pixels;
}