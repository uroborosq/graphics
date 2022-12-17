//
// Created by kotyangensss on 17.12.2022.
//

#ifndef HOROSHOEDITOR_MEDIANFILTERING_H
#define HOROSHOEDITOR_MEDIANFILTERING_H

#include <vector>
#include "AbstractFiltering.h"

class MedianFiltering : public AbstractFiltering {
public:
    int static radius;
    std::vector<float>& filter(std::vector<float>& pixels, int width, int height) override;
};

#endif //HOROSHOEDITOR_MEDIANFILTERING_H
