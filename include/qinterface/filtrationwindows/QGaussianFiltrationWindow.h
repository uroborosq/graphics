#ifndef HOROSHOEDITOR_QGAUSSIANFILTRATIONWINDOW_H
#define HOROSHOEDITOR_QGAUSSIANFILTRATIONWINDOW_H

#include <QDialog>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSpinBox>
#include <QPushButton>

class QGaussianFiltrationWindow : public QDialog {
private:
    bool isSubmitted;
    QSpinBox* sigmaBox = new QSpinBox();
    void addFilter();

public:
    QGaussianFiltrationWindow();
    bool checkSubmitted();
    int getSigma();
};

#endif //HOROSHOEDITOR_QGAUSSIANFILTRATIONWINDOW_H
