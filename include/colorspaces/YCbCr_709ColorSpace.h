//
// Created by kotyangensss on 06.11.2022.
//

#ifndef HOROSHOEDITOR_YCBCR_709COLORSPACE_H
#define HOROSHOEDITOR_YCBCR_709COLORSPACE_H

#include "AbstractColorSpace.h"

class YCbCr_709ColorSpace : public AbstractColorSpace {
public:
    std::vector<float> &toLinearRGB(std::vector<float> &) override;

    std::vector<float> &fromLinearRGB(std::vector<float> &) override;

};

#endif //HOROSHOEDITOR_YCBCR_709COLORSPACE_H
