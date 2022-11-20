//
// Created by uroborosq on 05.11.22.
//

#ifndef HOROSHOEDITOR_CMYCOLORSPACE_H
#define HOROSHOEDITOR_CMYCOLORSPACE_H
#include "AbstractColorSpace.h"

class CMYColorSpace : public AbstractColorSpace{
public:
    std::vector<float>& toLinearRGB(std::vector<float>&) override;
    std::vector<float>& fromLinearRGB(std::vector<float>&) override;
};
#endif //HOROSHOEDITOR_CMYCOLORSPACE_H
