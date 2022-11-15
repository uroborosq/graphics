//
// Created by uroborosq on 14.11.22.
//

#include "Pixels.h"
#include "selectcolorchannel.h"


Pixels::Pixels() {
    values = std::vector<float>();
    colorSpace = ColorSpace::RGB;
    colorChannel = ColorChannel::Все;
    width = 0;
    height = 0;
    format = PnmFormat::P6;
}

Pixels::Pixels(const std::vector<float> &values_, const int& width_, const int& height_, char* tag_, const ColorSpace& colorSpace_, const ColorChannel& colorChannel_) {
    values = values_;
    width = width_;
    height = height_;
    format = tag_[1] == '5' ? PnmFormat::P5 : PnmFormat::P6;
    colorSpace = colorSpace_;
    colorChannel = colorChannel_;
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

const int &Pixels::getWidth() {
    return width;
}

const int &Pixels::getHeight() {
    return height;
}

const PnmFormat& Pixels::getTag() {
    return format;
}


