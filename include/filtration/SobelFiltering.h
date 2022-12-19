//
// Created by kotyangensss on 17.12.2022.
//

#ifndef HOROSHOEDITOR_SOBELFILTERING_H
#define HOROSHOEDITOR_SOBELFILTERING_H

#include <vector>
#include "AbstractFiltering.h"

class SobelFiltering : public AbstractFiltering {
public:
    std::vector<float>& filter(std::vector<float>& pixels, int width, int height) override;
};

#endif //HOROSHOEDITOR_SOBELFILTERING_H
