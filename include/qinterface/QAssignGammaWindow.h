#ifndef HOROSHOEDITOR_QASSIGNGAMMAWINDOW_H
#define HOROSHOEDITOR_QASSIGNGAMMAWINDOW_H

#include <QWidget>
#include <QRadioButton>
#include <QComboBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QDoubleSpinBox>
#include <QDialog>

class QAssignGammaWindow : public QDialog {
public:
    explicit QAssignGammaWindow();
    bool checkSubmited();
    double getNewGamma();

private:
    QRadioButton* profileButton;
    QDoubleSpinBox* gammaBox;
    double sRGB = 0;
    bool isSubmitted;
    void changeGammaValue();
};

#endif //HOROSHOEDITOR_QASSIGNGAMMAWINDOW_H
