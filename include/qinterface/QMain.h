#ifndef HOROSHOEDITOR_QMAIN_H
#define HOROSHOEDITOR_QMAIN_H

#include <QWidget>
#include <QApplication>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
#include "Pnm.h"
#include "Pixels.h"
#include "QImageWidget.h"
#include <map>

class QMain : public QMainWindow {
private:
    int gradientCounter = 0;
    std::map<std::string, Pixels*> images;
    Pixels* currentPixels;
    QImageWidget* picture;
    QColor lineColor = Qt::red;
    int lineThickness = 1;
    float lineTransparency = 1;

public:
    QMain(Pixels*, QImageWidget*);
    void openOpenWindow();
    void openSaveWindow();
    void openColorSpaceAndChannelWindow();
    void openAssignGammaWindow();
    void openConvertGammaWindow();
    void openDrawLineWindow();
    void openLineParametersWindow();
    void openDitheringParametersWindow();
    void openGradientGenerationWindow();
    void openImageChooseDialog();
    void openTresholdFiltrationWindow();
    void openOtsuThresholdFiltrationWindow();
    void openMedianFiltrationWindow();
    void openGaussianFiltrationWindow();
    void openLinearAveragingFiltrationWindow();
    void openSobelFiltrationWindow();
    void openСontrastAdaptiveSharpeningFiltrationWindow();
};

#endif //HOROSHOEDITOR_QMAIN_H
