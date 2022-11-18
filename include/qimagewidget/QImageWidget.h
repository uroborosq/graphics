#ifndef QIMAGEWIDGET_H
#define QIMAGEWIDGET_H

#include <QLabel>
#include "PnmFormat.h"
#include "Pixels.h"

class QImageWidget : public QLabel
{
private:
    int _width;
    int _height;
    PnmFormat _format;
    std::vector<float> _displayPixels;
    float _gammaCorrection;
    void convertToRgb(const ColorSpace&);
    void proceedGammaCorrection(const float&);
    void reloadPixmap();
public:
    QImageWidget();
    explicit QImageWidget(Pixels *);
    void setGamma(float);
    const float& getGamma() const;
    void updatePixels();
};

#endif //QIMAGEWIDGET_H
