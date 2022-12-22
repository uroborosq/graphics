//
// Created by uroborosq on 21.11.22.
//

#ifndef HOROSHOEDITOR_RANDOMDITHERING_H
#define HOROSHOEDITOR_RANDOMDITHERING_H

#include "AbstractDithering.h"

class RandomDithering : public AbstractDithering {
public:
    std::vector<float>& proceed(std::vector<float>& pixels, int width, int depth, int numOfChannels);
};

#endif //HOROSHOEDITOR_RANDOMDITHERING_H
