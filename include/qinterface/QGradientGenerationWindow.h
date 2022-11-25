#ifndef HOROSHOEDITOR_QGRADIENTGENERATIONWINDOW_H
#define HOROSHOEDITOR_QGRADIENTGENERATIONWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QColor>
#include <QVBoxLayout>
#include <QColorDialog>
#include "QImageWidget.h"

class QGradientGenerationWindow : public QDialog {
private:
    bool isSubmitted;
    QPushButton* gradientButton;
    QSpinBox* widthBox;
    QSpinBox* heightBox;
    QColor leftColor = Qt::red;
    QColor rightColor = Qt::blue;
    QLabel* leftColorLabel;
    QLabel* rightColorLabel;
    Pixels *pixels;
    QImageWidget *picture;
    void changeLeftColor();
    void changeRightColor();
    void setDithering();
    void generateGradientPicture();
    void generateGrayscaleGradient();
public:
    QGradientGenerationWindow(int, int);
    bool checkSubmitted();
    Pixels* getGradient();
};

#endif //HOROSHOEDITOR_QGRADIENTGENERATIONWINDOW_H
