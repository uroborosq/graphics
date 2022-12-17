#ifndef HOROSHOEDITOR_QMEDIANFILTRATIONWINDOW_H
#define HOROSHOEDITOR_QMEDIANFILTRATIONWINDOW_H

#include <QDialog>
#include <QLabel>
#include <QHBoxLayout>
#include <QSpinBox>
#include <QPushButton>

class QMedianFiltrationWindow : public QDialog {
private:
    bool isSubmitted;
    QSpinBox* medianBox = new QSpinBox();
    void addFilter();

public:
    QMedianFiltrationWindow();
    bool checkSubmitted();
    int getRadius();
};

#endif //HOROSHOEDITOR_QMEDIANFILTRATIONWINDOW_H
