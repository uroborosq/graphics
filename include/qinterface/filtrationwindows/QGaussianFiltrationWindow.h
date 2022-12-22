#ifndef HOROSHOEDITOR_QGAUSSIANFILTRATIONWINDOW_H
#define HOROSHOEDITOR_QGAUSSIANFILTRATIONWINDOW_H

#include <QDialog>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSpinBox>
#include <QPushButton>
#include <QLineEdit>

class QGaussianFiltrationWindow : public QDialog {
private:
    bool isSubmitted;
    QDoubleSpinBox* sigmaBox;
    void addFilter();

public:
    QGaussianFiltrationWindow();
    bool checkSubmitted();
    float getSigma();
};

#endif //HOROSHOEDITOR_QGAUSSIANFILTRATIONWINDOW_H
