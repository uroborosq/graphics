//
// Created by uroborosq on 21.11.22.
//

#ifndef HOROSHOEDITOR_ATKINSONDITHERING_H
#define HOROSHOEDITOR_ATKINSONDITHERING_H

#include "AbstractDithering.h"

class AtkinsonDithering : public AbstractDithering {
public:
    std::vector<float> &proceed(std::vector<float> &pixels, int width, int depth, int numOfChannels) override;
};


#endif //HOROSHOEDITOR_ATKINSONDITHERING_H
