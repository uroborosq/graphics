//
// Created by kotyangensss on 15.12.2022.
//

#ifndef HOROSHOEDITOR_BCSPLINESINTERPOLATION_H
#define HOROSHOEDITOR_BCSPLINESINTERPOLATION_H

#include "AbstractInterpolation.h"

class BCSplinesInterpolation : public AbstractInterpolation {
public:
    static float b;
    static float c;
    std::vector<float> &interpolate(std::vector<float>& pixels,
                                    int width,
                                    int height,
                                    int newWidth,
                                    int newHeight,
                                    float x,
                                    float y,
                                    double b = 0,
                                    double c = 0.5) override;
};

#endif //HOROSHOEDITOR_BCSPLINESINTERPOLATION_H
