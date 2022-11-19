#ifndef HOROSHOEDITOR_QLINEPARAMETERSSELECTIONWINDOW_H
#define HOROSHOEDITOR_QLINEPARAMETERSSELECTIONWINDOW_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QColor>
#include <QColorDialog>
#include <QLineEdit>
#include <QSpinBox>
#include <QSlider>
#include <QGridLayout>

class QLineParametersSelectionWindow : public QDialog {

private:
    QColor color = Qt::red;
    QLabel* colorLabel;
    QSpinBox* lineThicknessValue;
    QSlider* lineTransparencyValue;
    bool isSubmitted;
    void changeColor();

public:
    QLineParametersSelectionWindow();
    bool checkSubmitted();
    void setLineParameters();
    QColor getColor();
    int getLineThickness();

};

#endif //HOROSHOEDITOR_QLINEPARAMETERSSELECTIONWINDOW_H
