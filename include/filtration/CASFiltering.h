//
// Created by kotyangensss on 17.12.2022.
//

#ifndef HOROSHOEDITOR_CASFILTERING_H
#define HOROSHOEDITOR_CASFILTERING_H

#include <vector>
#include "AbstractFiltering.h"

class CASFiltering : public AbstractFiltering {
public:
    std::vector<float> &filter(std::vector<float> &pixels, FilterConfiguration config, int width, int height) override;
};

#endif //HOROSHOEDITOR_CASFILTERING_H
