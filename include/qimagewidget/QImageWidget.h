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
    int _mousePressXCoordinate = 0;
    int _mousePressYCoordinate = 0;
    void convertToRgb(const ColorSpace&);
    void proceedGammaCorrection(const float&);
    void reloadPixmap();
Q_OBJECT
signals:
public:
    explicit QImageWidget(Pixels *, QWidget* parent, Qt::WindowFlags f = static_cast<Qt::WindowType>(0));
    void setGamma(float);
    const float& getGamma() const;
    int getMousePressXCoordinate();
    int getMousePressYCoordinate();
protected:
    void mousePressEvent( QMouseEvent* ev ) override;
};

#endif //QIMAGEWIDGET_H
