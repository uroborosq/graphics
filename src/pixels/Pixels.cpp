//
// Created by uroborosq on 14.11.22.
//

#include <stdexcept>
#include "Pixels.h"
#include "selectcolorchannel.h"
#include "GammaCorrection.h"


Pixels::Pixels() {
    values = std::vector<float>();
    colorSpace = ColorSpace::RGB;
    colorChannel = ColorChannel::All;
    width = 0;
    height = 0;
    format = PnmFormat::P6;
}

Pixels::Pixels(const std::vector<float> &values_, const int& width_, const int& height_, const char* tag_,
               const ColorSpace& colorSpace_=ColorSpace::RGB, const ColorChannel& colorChannel_=ColorChannel::All,
               const float& gamma_=1 / 2.2) {
    values = values_;
    width = width_;
    height = height_;
    format = tag_[1] == '5' ? PnmFormat::P5 : PnmFormat::P6;
    colorSpace = colorSpace_;
    colorChannel = colorChannel_;
    gamma = gamma_;
}

const std::vector<float> &Pixels::getValues() {
    auto filteredPixels = select_color_channel(values, colorChannel);
    return *filteredPixels;
}

const ColorSpace &Pixels::getColorSpace() {
    return colorSpace;
}

void Pixels::setColorSpace(const ColorSpace &colorSpace_) {
    if (colorSpace != ColorSpace::RGB)
    {
        AbstractColorSpace *converter = chooseConverter(colorSpace);
        if (converter != nullptr)
        {
            values = converter->to_rgb(values);
        }
    }
    AbstractColorSpace *converter = chooseConverter(colorSpace_);
    if (converter != nullptr)
    {
        values = converter->from_rgb(values);
    }

    colorSpace = colorSpace_;
}

const ColorChannel &Pixels::getColorChannel() {
    return colorChannel;
}

void Pixels::setColorChannel(const ColorChannel &colorChannel_) {
    colorChannel = colorChannel_;
}

const int &Pixels::getWidth() const {
    return width;
}

const int &Pixels::getHeight() const {
    return height;
}

const PnmFormat& Pixels::getTag() {
    return format;
}

const float &Pixels::getGamma() const {
    return gamma;
}

void Pixels::setGamma(const float & newGamma) {
    if (newGamma < 0)
        throw std::invalid_argument("Gamma's value can't be lower than zero");
    auto GammaCorrector = GammaCorrection();
    values = GammaCorrector.changeGamma(values, gamma, newGamma);
    gamma = newGamma;
}


