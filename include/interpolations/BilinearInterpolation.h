//
// Created by kotyangensss on 15.12.2022.
//

#ifndef HOROSHOEDITOR_BILINEARINTERPOLATION_H
#define HOROSHOEDITOR_BILINEARINTERPOLATION_H

#include "AbstractInterpolation.h"

class BilinearInterpolation : public AbstractInterpolation {
public:
    std::vector<float> &interpolate(std::vector<float>& pixels, int width, int height, int newWidth, int newHeight, float x, float y) override;
};

#endif //HOROSHOEDITOR_BILINEARINTERPOLATION_H
