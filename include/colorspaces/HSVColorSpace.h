//
// Created by uroborosq on 04.11.22.
//

#ifndef HOROSHOEDITOR_HSVCOLORSPACE_H
#define HOROSHOEDITOR_HSVCOLORSPACE_H
#include "AbstractColorSpace.h"

class HSVColorSpace : public AbstractColorSpace{
public:
    std::vector<float>& toLinearRGB(std::vector<float>&) override;
    std::vector<float>& fromLinearRGB(std::vector<float>&) override;
private:
    static void assign_pixels(std::size_t, std::vector<float>&, const float& ,const float&,const float&);

};



#endif //HOROSHOEDITOR_HSVCOLORSPACE_H
