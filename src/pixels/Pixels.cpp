//
// Created by uroborosq on 14.11.22.
//

#include <stdexcept>
#include "Pixels.h"
#include "selectcolorchannel.h"
#include "GammaCorrection.h"
#include "sRGBColorSpace.h"


Pixels::Pixels() {
    values = std::vector<float>();
    colorSpace = ColorSpace::RGB;
    colorChannel = ColorChannel::All;
    width = 0;
    height = 0;
    format = PnmFormat::P6;
}

Pixels::Pixels(const std::vector<float> &values_, const int &width_, const int &height_, const char *tag_,
               const ColorSpace &colorSpace_, const ColorChannel &colorChannel_,
               const float &gamma_) {
    values = values_;
    width = width_;
    height = height_;
    format = tag_[1] == '5' ? PnmFormat::P5 : PnmFormat::P6;
    colorSpace = colorSpace_;
    colorChannel = colorChannel_;
    gamma = gamma_;
}

const std::vector<float> &Pixels::getValues() {
    if (colorChannel != ColorChannel::All) {
        auto filteredPixels = select_color_channel(values, colorChannel);
        return *filteredPixels;
    }
    return values;
}

const ColorSpace &Pixels::getColorSpace() {
    return colorSpace;
}

void Pixels::setColorSpace(const ColorSpace &colorSpace_) {
    if (colorSpace != ColorSpace::RGB) {
        AbstractColorSpace *converter = chooseConverter(colorSpace);
        if (converter != nullptr) {
            values = converter->toLinearRGB(values);
        }
    }
    AbstractColorSpace *converter = chooseConverter(colorSpace_);
    if (converter != nullptr) {
        values = converter->fromLinearRGB(values);
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

const PnmFormat &Pixels::getTag() {
    return format;
}

const float &Pixels::getGamma() const {
    return gamma;
}

void Pixels::setGamma(const float &newGamma) {
    if (newGamma < 0)
        throw std::invalid_argument("Gamma's value can't be lower than zero");

    auto GammaCorrector = GammaCorrection();
    if (newGamma == 0 and gamma != 0) {
        values = GammaCorrector.changeGamma(values, gamma, 1);
        values = sRGBColorSpace().fromLinearRGB(values);
    }  else if (gamma == 0 and newGamma != 0) {
        values = sRGBColorSpace().toLinearRGB(values);
        values = GammaCorrector.changeGamma(values, 1, newGamma);
    }
    else if (gamma != newGamma) {
        values = GammaCorrector.changeGamma(values, gamma, newGamma);
    }
    gamma = newGamma;
}


