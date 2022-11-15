#ifndef _QIMAGEWIDGET_H
#define _QIMAGEWIDGET_H

#include <QLabel>
#include "PnmFormat.h"
#include "Pixels.h"

class QImageWidget : public QLabel
{
public:
    QImageWidget(Pixels *);
};

#endif //___QIMAGEWIDGET_H
