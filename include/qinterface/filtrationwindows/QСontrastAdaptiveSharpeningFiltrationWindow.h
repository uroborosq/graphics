#ifndef HOROSHOEDITOR_QСONTRASTADAPTIVESHARPENINGFILTRATIONWINDOW_H
#define HOROSHOEDITOR_QСONTRASTADAPTIVESHARPENINGFILTRATIONWINDOW_H

#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QSlider>

class QСontrastAdaptiveSharpeningFiltrationWindow : public QDialog {
private:
    bool isSubmitted;
    QSlider* sharpnessSlider = new QSlider();
    QLabel* sharpnessValue = new QLabel();
    void addFilter();
    void changeSharpnessValue();

public:
    QСontrastAdaptiveSharpeningFiltrationWindow();
    bool checkSubmitted();
    int getSharpness();
};
#endif //HOROSHOEDITOR_QСONTRASTADAPTIVESHARPENINGFILTRATIONWINDOW_H
