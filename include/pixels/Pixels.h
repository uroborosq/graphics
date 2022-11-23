#ifndef HOROSHOEDITOR_PIXELS_H
#define HOROSHOEDITOR_PIXELS_H


#include <vector>
#include "ColorSpaceEnum.h"
#include "ColorChannelEnum.h"
#include "AbstractColorSpace.h"
#include "AbstractDrawLine.h"
#include "PnmFormat.h"
#include "DitheringEnum.h"

class Pixels {
private:
    std::vector<float> values;
    ColorSpace colorSpace;
    ColorChannel colorChannel;
    int width;
    int height;
    float gamma;
    PnmFormat format;
    Dithering dithering;
    int ditheringDepth;
public:
    Pixels();
    Pixels(const std::vector<float> &values_, const int& width_, const int& height_, const char* tag_,
           const ColorSpace& colorSpace_ = ColorSpace::RGB, const ColorChannel& colorChannel_ = ColorChannel::All,
           const float& gamma_ = 0);
    std::vector<float> getValues();
    const ColorSpace& getColorSpace();
    void setColorSpace(const ColorSpace&);
    const ColorChannel& getColorChannel();
    void setColorChannel(const ColorChannel&);
    const int& getWidth() const;
    const int& getHeight() const;
    const PnmFormat& getTag();
    const float& getGamma() const;
    void setGamma(const float&);
    void setDithering(const Dithering& dithering_, int ditheringDepth_);
    const Dithering& getDithering();
    void drawLine(AbstractDrawLine *drawer, const long long &x0, const long long &y0, const long long &x1, const long long &y1,
                          std::vector<float> &color, const int &lineWidth, const float& transparency);
};


#endif //HOROSHOEDITOR_PIXELS_H
    