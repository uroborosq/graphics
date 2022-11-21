//
// Created by kotyangensss on 21.11.2022.
//

#include "Gradient.h"


std::vector<float> &Gradient::drawGradient(const int &fileWidth, const int &fileHeight, std::vector<float> &leftColor,
                                           std::vector<float> &rightColor) {
    auto *values = new std::vector<float>(fileWidth * fileHeight * leftColor.size(), 0);
    for (int w = 0; w < fileWidth; w++) {
        for (int h = 0; h < fileHeight; h++) {
            for (int i = 0; i < leftColor.size(); i++){
                values->at((h * fileWidth + w) * leftColor.size() + i) = leftColor[i] + (rightColor[i] - leftColor[i]) * w /fileWidth;
            }
        }
    }
    return *values;
}