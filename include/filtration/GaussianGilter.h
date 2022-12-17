//
// Created by kotyangensss on 17.12.2022.
//

#ifndef HOROSHOEDITOR_GAUSSIANGILTER_H
#define HOROSHOEDITOR_GAUSSIANGILTER_H

#include <vector>
#include "AbstractFiltering.h"

class GaussianFiltering : public AbstractFiltering {
public:
    bool static isUpper;
    std::vector<float>& filter(std::vector<float>& pixels) override;
};

#endif //HOROSHOEDITOR_GAUSSIANGILTER_H
