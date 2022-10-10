#ifndef ___QIMAGEWIDGET_H
#define ___QIMAGEWIDGET_H

#include <QLabel>

class QImageWidget : public QLabel
{
public:
    QImageWidget(std::vector<uint8_t>, const int&, const int&, char*);
};

#endif //___QIMAGEWIDGET_H
