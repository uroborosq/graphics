#include "QImageWidget.h"
#include "GammaCorrection.h"
#include "sRGBColorSpace.h"
#include <iostream>

QImageWidget::QImageWidget(Pixels *pixels) {
    _format = pixels->getTag();
    _height = pixels->getHeight();
    _width = pixels->getWidth();
    _displayPixels = pixels->getValues();
    _gammaCorrection = 0;

    convertToRgb(pixels->getColorSpace());
    proceedGammaCorrection(pixels->getGamma());
    reloadPixmap();
}


void QImageWidget::setGamma(float newGamma) {
    if (newGamma < 0) {
        throw std::invalid_argument("Gamma can't be lower than zero");
    }
    if (_gammaCorrection != newGamma) {
        auto oldGamma = _gammaCorrection;
        _gammaCorrection = newGamma;

        proceedGammaCorrection(oldGamma);
        reloadPixmap();
    }
}

const float &QImageWidget::getGamma() const {
    return _gammaCorrection;
}

void QImageWidget::convertToRgb(const ColorSpace &colorSpace) {
    if (colorSpace != ColorSpace::RGB) {
        auto converter = chooseConverter(colorSpace);
        _displayPixels = converter->toLinearRGB(_displayPixels);
    }
}

void QImageWidget::proceedGammaCorrection(const float &pixelsGamma) {
    auto gammaCorrector = GammaCorrection();
    if (pixelsGamma != _gammaCorrection) {
        // если мы хотим показать в какой-то гамме а у нас sRGB
        if (pixelsGamma == 0) {
            _displayPixels = sRGBColorSpace().toLinearRGB(_displayPixels);
            _displayPixels = gammaCorrector.changeGamma(_displayPixels, 1, _gammaCorrection);
            // если мы хотим показать в sRGB а у нас какая то гамма
        } else if (_gammaCorrection == 0) {

            _displayPixels = gammaCorrector.changeGamma(_displayPixels, pixelsGamma, 1);
            _displayPixels = sRGBColorSpace().fromLinearRGB(_displayPixels);
        } else {
            _displayPixels = gammaCorrector.changeGamma(_displayPixels, pixelsGamma, _gammaCorrection);
        }
    }
}

void QImageWidget::reloadPixmap() {
    auto image = QImage(_width, _height, QImage::Format_RGB888);
    if (_format == PnmFormat::P6) {
        for (int i = 0; i < _height; ++i) {
            for (int j = 0; j < _width; ++j) {
                auto offset = i * _width * 3 + j * 3;
                auto value = qRgb(uint_fast8_t(std::round(_displayPixels[offset])),
                                  uint_fast8_t(std::round(_displayPixels[offset + 1])),
                                  uint_fast8_t(std::round(_displayPixels[offset + 2])));
                image.setPixel(j, i, value);
            }
        }

    } else if (_format == PnmFormat::P5) {
        for (int i = 0; i < _height; ++i) {
            for (int j = 0; j < _width; ++j) {
                auto offset = i * _width + j;
                auto pixel_value = uint8_t(_displayPixels[offset]);
                auto value = qRgb(pixel_value, pixel_value, pixel_value);
                image.setPixel(j, i, value);
            }
        }
    }
    auto pixmap = QPixmap::fromImage(image);
    setPixmap(pixmap);
}
