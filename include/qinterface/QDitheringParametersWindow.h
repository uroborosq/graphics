#ifndef HOROSHOEDITOR_QDITHERINGPARAMETERSWINDOW_H
#define HOROSHOEDITOR_QDITHERINGPARAMETERSWINDOW_H

#include <QDialog>
#include <QLabel>
#include <QComboBox>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QSlider>
#include <QPushButton>
#include "QImageWidget.h"
#include "QMain.h"
#include "DitheringEnum.h"

class QDitheringParametersWindow : public QDialog {
private:
    bool isSubmitted;
    QComboBox* algorithmComboBox;
    QSlider* bitDepthSlider;
    QLabel* bitDepthValue;
    QImageWidget* _ditheringPicture;
    Pixels* _pixels;
    QMain* _mainWindow;
    void showPreview();
    void changeBitDepth();
    void setDithering();
    Dithering getAlgorithm();
    int getBitDepth();

public:
    QDitheringParametersWindow(Pixels*, QMain*);
    bool checkSubmitted();
    Pixels* getDitheringPixels();
    QImageWidget* getDitheringPicture();
};

#endif //HOROSHOEDITOR_QDITHERINGPARAMETERSWINDOW_H
