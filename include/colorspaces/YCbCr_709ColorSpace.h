//
// Created by kotyangensss on 06.11.2022.
//

#ifndef HOROSHOEDITOR_YCBCR_709_H
#define HOROSHOEDITOR_YCBCR_709_H

#include "AbstractColorSpace.h"

class YCbCr_709ColorSpace : public AbstractColorSpace {
public:
    std::vector<float> &to_rgb(std::vector<float> &) override;

    std::vector<float> &from_rgb(std::vector<float> &) override;

};

#endif //HOROSHOEDITOR_YCBCR_709_H
