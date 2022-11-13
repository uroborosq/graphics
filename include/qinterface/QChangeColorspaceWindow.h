#ifndef HOROSHOEDITOR_QCHANGECOLORSPACEWINDOW_H
#define HOROSHOEDITOR_QCHANGECOLORSPACEWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <QVBoxLayout>
#include <QPushButton>
#include "Pnm.h"
#include "AbstractColorSpace.h"
#include "CMYColorSpace.h"
#include "HSLColorSpace.h"
#include "HSVColorSpace.h"
#include "YCbCr_601ColorSpace.h"
#include "YCbCr_709ColorSpace.h"
#include "YCoCgColorSpace.h"
#include "selectcolorchannel.h"
#include "QImageWidget.h"
#include "QMain.h"

class QChangeColorspaceWindow : public QWidget {
public:
    explicit QChangeColorspaceWindow(Pnm* file, QMain* mainWindow);
    void ChangeImageColorspace(AbstractColorSpace& converter, int colorchannel, Pnm* file, QMain* mainWindow);
};

#endif //HOROSHOEDITOR_QCHANGECOLORSPACEWINDOW_H
