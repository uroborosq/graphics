//
// Created by uroborosq on 14.11.22.
//

#ifndef HOROSHOEDITOR_PIXELS_H
#define HOROSHOEDITOR_PIXELS_H


#include <vector>
#include "ColorSpaceEnum.h"
#include "ColorChannelEnum.h"
#include "AbstractColorSpace.h"
#include "PnmFormat.h"
class Pixels {
private:
    std::vector<float> values;
    ColorSpace colorSpace;
    ColorChannel colorChannel;
    int width;
    int height;
    float gamma;
    PnmFormat format;
public:
    Pixels();
    Pixels(const std::vector<float> &values_, const int& width_, const int& height_, const char* tag_,
           const ColorSpace& colorSpace_, const ColorChannel& colorChannel_,
           const float& gamma_);
    const std::vector<float>& getValues();
    const ColorSpace& getColorSpace();
    void setColorSpace(const ColorSpace&);
    const ColorChannel& getColorChannel();
    void setColorChannel(const ColorChannel&);
    const int& getWidth() const;
    const int& getHeight() const;
    const PnmFormat& getTag();
    const float& getGamma() const;
    void setGamma(const float&);
};


#endif //HOROSHOEDITOR_PIXELS_H
