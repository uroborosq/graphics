#ifndef ___QIMAGEWIDGET_H
#define ___QIMAGEWIDGET_H

#include <QLabel>

class QImageWidget : public QLabel
{
public:
    QImageWidget(std::vector<float>, const int&, const int&, char*);
};

#endif //___QIMAGEWIDGET_H
