#ifndef HOROSHOEDITOR_QCONTRASTADAPTIVESHARPENINGFILTRATIONWINDOW_H
#define HOROSHOEDITOR_QCONTRASTADAPTIVESHARPENINGFILTRATIONWINDOW_H

#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QSlider>

class QContrastAdaptiveSharpeningFiltrationWindow : public QDialog {
private:
    bool isSubmitted;
    QSlider* sharpnessSlider = new QSlider();
    QLabel* sharpnessValue = new QLabel();
    void addFilter();
    void changeSharpnessValue();

public:
    QContrastAdaptiveSharpeningFiltrationWindow();
    bool checkSubmitted();
    int getSharpness();
};
#endif //HOROSHOEDITOR_QCONTRASTADAPTIVESHARPENINGFILTRATIONWINDOW_H
