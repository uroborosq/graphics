//
// Created by kotyangensss on 17.12.2022.
//

#ifndef HOROSHOEDITOR_BOXBLURFILTERING_H
#define HOROSHOEDITOR_BOXBLURFILTERING_H

#include <vector>
#include "AbstractFiltering.h"
#include "FilterConfiguration.h"

class BoxBlurFiltering : public AbstractFiltering {
public:
    std::vector<float> &filter(std::vector<float> &pixels, FilterConfiguration config, int width, int height) override;
};

#endif //HOROSHOEDITOR_BOXBLURFILTERING_H
