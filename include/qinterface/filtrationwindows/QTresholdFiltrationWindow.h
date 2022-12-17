#ifndef HOROSHOEDITOR_QTRESHOLDFILTRATIONWINDOW_H
#define HOROSHOEDITOR_QTRESHOLDFILTRATIONWINDOW_H

#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QSlider>

class QTresholdFiltrationWindow : public QDialog {
private:
    bool isSubmitted;
    QSlider* thresholdFiltrationSlider = new QSlider();
    QLabel* thresholdFiltrationValue = new QLabel();
    void addFilter();
    void changeTresholdValue();

public:
    QTresholdFiltrationWindow();
    bool checkSubmitted();
    int getThresholdValue();
};

#endif //HOROSHOEDITOR_QTRESHOLDFILTRATIONWINDOW_H
