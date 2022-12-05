#ifndef HOROSHOEDITOR_QCHANGECOLORSPACEWINDOW_H
#define HOROSHOEDITOR_QCHANGECOLORSPACEWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <QVBoxLayout>
#include <QPushButton>
#include <QDialog>
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
#include "Pixels.h"

class QChangeColorspaceWindow : public QDialog {
public:
    explicit QChangeColorspaceWindow(const ColorSpace& currentColorSpace, const ColorChannel& currentColorChannel);
    ColorSpace getColorSpace();
    ColorChannel getColorChannel();
    bool checkSubmitted();

private:
    QComboBox* colorspaces;
    bool isSubmitted;
    void changeColorSpace();
    QComboBox* changeColorChannelBox(int index, const ColorChannel& currentColorChannel);
};

#endif //HOROSHOEDITOR_QCHANGECOLORSPACEWINDOW_H
