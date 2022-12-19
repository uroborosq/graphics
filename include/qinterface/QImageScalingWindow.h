#ifndef HOROSHOEDITOR_QIMAGESCALINGWINDOW_H
#define HOROSHOEDITOR_QIMAGESCALINGWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpinBox>
#include <QComboBox>
#include <QPushButton>
#include "InterpolationEnum.h"

class QImageScalingWindow : public QWidget {
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
};

#endif //HOROSHOEDITOR_QIMAGESCALINGWINDOW_H
