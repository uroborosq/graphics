//
// Created by kotyangensss on 17.11.2022.
//

#ifndef HOROSHOEDITOR_GAMMACORRECTION_H
#define HOROSHOEDITOR_GAMMACORRECTION_H

#include <vector>

class GammaCorrection{
public:
    std::vector<float>& changeGamma(std::vector<float>&,const float&,const float&);
};

#endif //HOROSHOEDITOR_GAMMACORRECTION_H
