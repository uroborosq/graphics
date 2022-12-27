//
// Created by kotyangensss on 15.12.2022.
//

#ifndef HOROSHOEDITOR_NEARESTNEIGHBOURINTERPOLATION_H
#define HOROSHOEDITOR_NEARESTNEIGHBOURINTERPOLATION_H

#include "AbstractInterpolation.h"

class NearestNeighbourInterpolation : public AbstractInterpolation {
public:
    std::vector<float> &interpolate(std::vector<float>& pixels,
                                    int width,
                                    int height,
                                    int newWidth,
                                    int newHeight,
                                    float x,
                                    float y,
                                    double b,
                                    double c) override;
};

#endif //HOROSHOEDITOR_NEARESTNEIGHBOURINTERPOLATION_H
