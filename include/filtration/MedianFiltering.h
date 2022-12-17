//
// Created by kotyangensss on 17.12.2022.
//

#ifndef HOROSHOEDITOR_MEDIANFILTERING_H
#define HOROSHOEDITOR_MEDIANFILTERING_H

#include <vector>
#include "AbstractFiltering.h"

class MedianFiltering : public AbstractFiltering {
public:
    bool static isUpper;
    std::vector<float>& filter(std::vector<float>& pixels) override;
};

#endif //HOROSHOEDITOR_MEDIANFILTERING_H
