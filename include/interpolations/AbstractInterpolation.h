//
// Created by kotyangensss on 15.12.2022.
//

#ifndef HOROSHOEDITOR_ABSTRACTINTERPOLATION_H
#define HOROSHOEDITOR_ABSTRACTINTERPOLATION_H

#include <vector>

class AbstractInterpolation {
public:
    virtual std::vector<float> &interpolate(std::vector<float>& pixels, int width, int height, int newWidth, int newHeight, float x, float y) = 0;
};

#endif //HOROSHOEDITOR_ABSTRACTINTERPOLATION_H
