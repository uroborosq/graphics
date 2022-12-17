//
// Created by kotyangensss on 17.12.2022.
//

#ifndef HOROSHOEDITOR_BOXBLURFILTERING_H
#define HOROSHOEDITOR_BOXBLURFILTERING_H

#include <vector>
#include "AbstractFiltering.h"

class BoxBlurFiltering : public AbstractFiltering {
public:
    bool static isUpper;
    std::vector<float>& filter(std::vector<float>& pixels) override;
};

#endif //HOROSHOEDITOR_BOXBLURFILTERING_H
