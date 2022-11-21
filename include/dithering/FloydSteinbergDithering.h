//
// Created by uroborosq on 21.11.22.
//

#ifndef HOROSHOEDITOR_FLOYDSTEINBERGDITHERING_H
#define HOROSHOEDITOR_FLOYDSTEINBERGDITHERING_H

#include "AbstractDithering.h"

class FloydSteinbergDithering : public AbstractDithering {
public:
    std::vector<float> &proceed(std::vector<float> &pixels, int width, int depth, bool isColorful) override;
};

#endif //HOROSHOEDITOR_FLOYDSTEINBERGDITHERING_H
