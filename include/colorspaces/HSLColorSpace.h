//
// Created by UroborosQ on 03.11.2022.
//

#ifndef HOROSHOEDITOR_HSLCOLORSPACE_H
#define HOROSHOEDITOR_HSLCOLORSPACE_H
#include "AbstractColorSpace.h"

class HSLColorSpace : public AbstractColorSpace{
public:
    std::vector<float>& to_rgb(std::vector<float>&) override;
    std::vector<float>& from_rgb(std::vector<float>&) override;
};


#endif //HOROSHOEDITOR_HSLCOLORSPACE_H
