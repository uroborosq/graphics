#ifndef HOROSHOEDITOR_QBCSPLINEWINDOW_H
#define HOROSHOEDITOR_QBCSPLINEWINDOW_H

#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QHBoxLayout>
#include <QDoubleSpinBox>
#include <QPushButton>

class QBCSplineWindow : public QDialog {
private:
    bool isSubmitted;
    QDoubleSpinBox* bBox;
    QDoubleSpinBox* cBox;
    void changeParameters();

public:
    QBCSplineWindow(double bValue = 0, double cValue = 0.5);
    bool checkSubmitted();
    double getBValue();
    double getCValue();
};

#endif //HOROSHOEDITOR_QBCSPLINEWINDOW_H
