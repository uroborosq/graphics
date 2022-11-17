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

class QConvertGammaWindow : public QWidget {
public:
    explicit QConvertGammaWindow();

private:
    QLabel* sourceSpaceLabel;
    QDoubleSpinBox* destinationSpaceSpinBox;
    void changeGammaValue();
};

#endif //HOROSHOEDITOR_QCONVERTGAMMAWINDOW_H
