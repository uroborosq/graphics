//
// Created by kotyangensss on 17.12.2022.
//

#ifndef HOROSHOEDITOR_OTSUTHRESHOLDFILTERING_H
#define HOROSHOEDITOR_OTSUTHRESHOLDFILTERING_H

#include <vector>
#include "AbstractFiltering.h"

class OtsuThresholdFiltering : public AbstractFiltering {
public:
    bool static isUpper;
    std::vector<float>& filter(std::vector<float>& pixels, int width, int height) override;
};

#endif //HOROSHOEDITOR_OTSUTHRESHOLDFILTERING_H
