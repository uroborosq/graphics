#ifndef HOROSHOEDITOR_SRGBCOLORSPACE_H
#define HOROSHOEDITOR_SRGBCOLORSPACE_H

#include "AbstractColorSpace.h"

class sRGBColorSpace : public AbstractColorSpace {
public:
    std::vector<float> &toLinearRGB(std::vector<float> &pixels) override;

    std::vector<float> &fromLinearRGB(std::vector<float> &pixels) override;

private:
    float linearTosRGB(float);
    float sRGBToLinear(float);
};

#endif 