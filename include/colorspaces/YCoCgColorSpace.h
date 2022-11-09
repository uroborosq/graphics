//
// Created by kotyangensss on 06.11.2022.
//

#ifndef HOROSHOEDITOR_YCOCGCOLORSPACE_H
#define HOROSHOEDITOR_YCOCGCOLORSPACE_H

#include "AbstractColorSpace.h"

class YCoCgColorSpace : public AbstractColorSpace {
public:
    std::vector<float> &to_rgb(std::vector<float> &) override;

    std::vector<float> &from_rgb(std::vector<float> &) override;

};

#endif //HOROSHOEDITOR_YCOCGCOLORSPACE_H
