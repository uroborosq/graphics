#ifndef HOROSHOEDITOR_QIMAGESCALINGWINDOW_H
#define HOROSHOEDITOR_QIMAGESCALINGWINDOW_H

#include <QDialog>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpinBox>
#include <QComboBox>
#include <QPushButton>
#include "InterpolationEnum.h"

class QImageScalingWindow : public QDialog {
private:
    bool isSubmitted;
    double bValue = 0;
    double cValue = 0.5;
    QSpinBox* widhtBox;
    QSpinBox* heightBox;
    QSpinBox* xBox;
    QSpinBox* yBox;
    QComboBox* scalingComboBox;
    void scaleImage();
    void bcSpline();

public:
    QImageScalingWindow();
    bool checkSubmitted();
    Interpolation getInterpolationParameters();
    int getWidth();
    int getHeight();
    int getXShift();
    int getYShift();
    double getBValue();
    double getCValue();
};

#endif //HOROSHOEDITOR_QIMAGESCALINGWINDOW_H
