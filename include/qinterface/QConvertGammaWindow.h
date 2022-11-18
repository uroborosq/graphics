#ifndef HOROSHOEDITOR_QCONVERTGAMMAWINDOW_H
#define HOROSHOEDITOR_QCONVERTGAMMAWINDOW_H

#include <QWidget>
#include <QRadioButton>
#include <QComboBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include <QDoubleSpinBox>
#include <QDialog>

class QConvertGammaWindow : public QDialog {
public:
    explicit QConvertGammaWindow(double);
    bool checkSubmited();
    double getNewGamma();

private:
    double sourseSpaceValue = 2.2;
    QLabel* sourceSpaceLabel;
    QDoubleSpinBox* destinationSpaceSpinBox;
    bool isSubmitted;
    void changeGammaValue();
};

#endif //HOROSHOEDITOR_QCONVERTGAMMAWINDOW_H
