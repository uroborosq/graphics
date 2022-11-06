//
// Created by kotyangensss on 06.11.2022.
//

#ifndef HOROSHOEDITOR_YCBCR_601COLORSPACE_H
#define HOROSHOEDITOR_YCBCR_601COLORSPACE_H

#include "AbstractColorSpace.h"

class YCbCr_601ColorSpace : public AbstractColorSpace {
public:
    std::vector<float> &to_rgb(std::vector<float> &) override;

    std::vector<float> &from_rgb(std::vector<float> &) override;

};

#endif //HOROSHOEDITOR_YCBCR_601COLORSPACE_H
