//
// Created by kotyangensss on 17.12.2022.
//

#ifndef HOROSHOEDITOR_SOBELFILTERING_H
#define HOROSHOEDITOR_SOBELFILTERING_H

#include <vector>
#include "AbstractFiltering.h"

class SobelFiltering : public AbstractFiltering {
public:
    bool static isUpper;
    std::vector<float>& filter(std::vector<float>& pixels) override;
};

#endif //HOROSHOEDITOR_SOBELFILTERING_H
