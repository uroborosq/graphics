#ifndef HOROSHOEDITOR_PIXELS_H
#define HOROSHOEDITOR_PIXELS_H


#include <vector>
#include "ColorSpaceEnum.h"
#include "ColorChannelEnum.h"
#include "AbstractColorSpace.h"
#include "AbstractDrawLine.h"
#include "DitheringEnum.h"
#include "FileFormatType.h"
#include "InterpolationEnum.h"
#include "AbstractFiltering.h"
#include "FiltrationEnum.h"

class Pixels {
private:
    std::vector<float> values;
    ColorSpace colorSpace;
    ColorChannel colorChannel;
    int numColorChannels;
    int width;
    int height;
    float gamma;
    FileFormatType format;
    Dithering dithering;
    Filtration filtration;
    FilterConfiguration filterConfiguration;
    int ditheringDepth;
    Interpolation interpolation;
    int scalingWidth;
    int scalingHeight;
    int scalingShiftX;
    int scalingShiftY;
    double bSpline;
    double cSpline;
public:
    Pixels();
    Pixels(const std::vector<float> &values_, const int& width_, const int& height_, FileFormatType format_, int numColorChannels_,
           const ColorSpace& colorSpace_ = ColorSpace::RGB, const ColorChannel& colorChannel_ = ColorChannel::All,
           const float& gamma_ = 0);
    std::vector<float> getValues();
    const ColorSpace& getColorSpace();
    void setColorSpace(const ColorSpace&);
    const ColorChannel& getColorChannel();
    void setColorChannel(const ColorChannel&);
    const int& getWidth() const;
    const int& getHeight() const;
    FileFormatType getTag();
    const float& getGamma() const;
    void setGamma(const float&);
    void setDithering(const Dithering& dithering_, int ditheringDepth_);
    const Dithering& getDithering();
    void drawLine(AbstractDrawLine *drawer, const long long &x0, const long long &y0, const long long &x1, const long long &y1,
                          std::vector<float> &color, const int &lineWidth, const float& transparency);
    int getNumberOfChannels();
    void setInterpolation(Interpolation, int &width, int &height, int &x, int &y, double &bSpline, double &cSpline);
    Interpolation& getInterpolation();
    void setFiltering(Filtration type, FilterConfiguration);
    Filtration getFiltering();
};


#endif //HOROSHOEDITOR_PIXELS_H
    