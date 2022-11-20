//
// Created by uroborosq on 20.11.22.
//

#include <cmath>

int nearestColor(int bit, double pixel_color) {
    if (pixel_color < 128)
        auto a = 1;
    int differenceBetweenColorLevels = std::pow(2, 9 - bit);
    int power = std::round(pixel_color  / differenceBetweenColorLevels);
    return power == 0 ? 0 : differenceBetweenColorLevels * power - 1;
}