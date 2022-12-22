//
// Created by kotynagensss on 17.12.2022.
//

#ifndef HOROSHOEDITOR_THRESHOLDFILTERING_H
#define HOROSHOEDITOR_THRESHOLDFILTERING_H

#include <vector>
#include "AbstractFiltering.h"

class ThresholdFiltering : public AbstractFiltering {
public:

    std::vector<float> &filter(std::vector<float> &pixels, FilterConfiguration config, int width, int height) override;
};

#endif //HOROSHOEDITOR_THRESHOLDFILTERING_H
