//
// Created by kotyangensss on 17.12.2022.
//

#ifndef HOROSHOEDITOR_ABSTRACTFILTERING_H
#define HOROSHOEDITOR_ABSTRACTFILTERING_H

#include <vector>
#include "FilterConfiguration.h"

class AbstractFiltering
{
public:
    virtual std::vector<float> &filter(std::vector<float> &pixels, FilterConfiguration config, int width, int height) = 0;
};
#endif //HOROSHOEDITOR_ABSTRACTFILTERING_H
