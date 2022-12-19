//
// Created by kotyangensss on 17.12.2022.
//

#ifndef HOROSHOEDITOR_BOXBLURFILTERING_H
#define HOROSHOEDITOR_BOXBLURFILTERING_H

#include <vector>
#include "AbstractFiltering.h"

class BoxBlurFiltering : public AbstractFiltering {
public:
    int static radius;
    std::vector<float>& filter(std::vector<float>& pixels, int width, int height) override;
};

#endif //HOROSHOEDITOR_BOXBLURFILTERING_H
