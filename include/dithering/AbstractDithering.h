//
// Created by uroborosq on 20.11.22.
//

#ifndef HOROSHOEDITOR_ABSTRACTDITHERING_H
#define HOROSHOEDITOR_ABSTRACTDITHERING_H

#include <vector>

class AbstractDithering
{
public:
    virtual std::vector<float>& proceed(std::vector<float>& pixels, int width, int depth, int numOfChannels)= 0;
};


#endif //HOROSHOEDITOR_ABSTRACTDITHERING_H
