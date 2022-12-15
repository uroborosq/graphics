//
// Created by uroborosq on 14.11.22.
//

#include <stdexcept>
#include "Pixels.h"
#include "selectcolorchannel.h"
#include "GammaCorrection.h"
#include "sRGBColorSpace.h"
#include "DitheringMethodFactory.h"

Pixels::Pixels() {
    values = std::vector<float>();
    colorSpace = ColorSpace::RGB;
    colorChannel = ColorChannel::All;
    width = 0;
    height = 0;
    format = FileFormat::PnmP5;
    dithering = Dithering::None;
    gamma = 0;
}

Pixels::Pixels(const std::vector<float> &values_, const int &width_, const int &height_, FileFormat _format, int numColorChannels_,
               const ColorSpace &colorSpace_, const ColorChannel &colorChannel_,
               const float &gamma_) {
    auto size = values_.size();
    for (std::size_t i = 0; i < size; i++)
        values.push_back(values_[i]);
    width = width_;
    height = height_;
    format = _format;
    colorSpace = colorSpace_;
    colorChannel = colorChannel_;
    gamma = gamma_;
    numColorChannels = numColorChannels_;
    dithering = Dithering::None;
}

std::vector<float> Pixels::getValues() {
    std::vector<float> valuesToSend;

    auto size = values.size();
    for (std::size_t i = 0; i < size; i++)
        valuesToSend.push_back(values[i]);
    if (dithering != Dithering::None) {
        valuesToSend = DitheringMethodFactory::create(dithering)->proceed(valuesToSend, width, ditheringDepth,
                                                                          colorChannel == ColorChannel::All ? 3 : 1);
    }

    if (colorChannel != ColorChannel::All) {
        valuesToSend = select_color_channel(valuesToSend, colorChannel);
    }

    return valuesToSend;
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

FileFormat Pixels::getTag() {
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
    } else if (gamma == 0 and newGamma != 0) {
        values = sRGBColorSpace().toLinearRGB(values);
        values = GammaCorrector.changeGamma(values, 1, newGamma);
    } else if (gamma != newGamma) {
        values = GammaCorrector.changeGamma(values, gamma, newGamma);
    }
    gamma = newGamma;
}

void Pixels::setDithering(const Dithering &dithering_, int ditheringDepth_) {
    if (ditheringDepth_ > 8 or ditheringDepth_ < 1)
        throw std::invalid_argument("depth must be between 1 and 8");
    ditheringDepth = ditheringDepth_;
    dithering = dithering_;
}

const Dithering &Pixels::getDithering() {
    return dithering;
}

void Pixels::drawLine(AbstractDrawLine *drawer, const long long &x0, const long long &y0, const long long &x1,
                      const long long &y1,
                      std::vector<float> &color, const int &lineWidth, const float &transparency) {
    values = drawer->drawLine(values, width, height, lineWidth, transparency, x0, y0, x1, y1, color);
}

int Pixels::getNumberOfChannels() {
    return numColorChannels;
}
