#include "QImageWidget.h"
#include "GammaCorrection.h"
#include <iostream>
#include <QSinglePointEvent>

QImageWidget::QImageWidget(Pixels *pixels, QWidget* parent, Qt::WindowFlags f) : QLabel(parent, f) {
    _format = pixels->getTag();
    _height = pixels->getHeight();
    _width = pixels->getWidth();
    _displayPixels = pixels->getValues();
    _gammaCorrection = 1 / 2.2;

    convertToRgb(pixels->getColorSpace());
    proceedGammaCorrection(pixels->getGamma());
    reloadPixmap();
}


void QImageWidget::setGamma(float newGamma) {
    if (newGamma == 0)
    {
        newGamma = 1 / 2.2;
    }


    if (newGamma < 0) {
        throw std::invalid_argument("Gamma can't be lower than zero");
    }
    auto oldGamma = _gammaCorrection;
    _gammaCorrection = newGamma;

    proceedGammaCorrection(oldGamma);
    reloadPixmap();
}

const float &QImageWidget::getGamma() const {
    return _gammaCorrection;
}

void QImageWidget::convertToRgb(const ColorSpace &colorSpace) {
    if (colorSpace != ColorSpace::RGB) {
        auto converter = chooseConverter(colorSpace);
        _displayPixels = converter->to_rgb(_displayPixels);
    }
}

void QImageWidget::proceedGammaCorrection(const float& pixelsGamma) {
    if (pixelsGamma != _gammaCorrection)
    {
        auto gammaCorrecter = GammaCorrection();
        _displayPixels = gammaCorrecter.changeGamma(_displayPixels, pixelsGamma, _gammaCorrection);
    }
}

void QImageWidget::reloadPixmap() {
    auto image = QImage(_width, _height, QImage::Format_RGB888);
    if (_format == PnmFormat::P6) {
        for (int i = 0; i < _height; ++i) {
            for (int j = 0; j < _width; ++j) {
                auto offset = i * _width * 3 + j * 3;
                auto value = qRgb(uint_fast8_t (std::round(_displayPixels[offset])),
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

void QImageWidget::mousePressEvent(QMouseEvent *event) {
    auto hm = (QSinglePointEvent*)event;
    QPoint p = hm->position().toPoint();
    _mousePressXCoordinate = p.x();
    _mousePressYCoordinate = p.y();
}

int QImageWidget::getMousePressXCoordinate() {
    return _mousePressXCoordinate;
}

int QImageWidget::getMousePressYCoordinate() {
    return _mousePressYCoordinate;
}