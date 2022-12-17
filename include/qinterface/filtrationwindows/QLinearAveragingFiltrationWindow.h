#ifndef HOROSHOEDITOR_QLINEARAVERAGINGFILTRATIONWINDOW_H
#define HOROSHOEDITOR_QLINEARAVERAGINGFILTRATIONWINDOW_H

#include <QDialog>
#include <QLabel>
#include <QHBoxLayout>
#include <QSpinBox>
#include <QPushButton>

class QLinearAveragingFiltrationWindow : public QDialog {
private:
    bool isSubmitted;
    QSpinBox* radiusBox = new QSpinBox();
    void addFilter();

public:
    QLinearAveragingFiltrationWindow();
    bool checkSubmitted();
    int getRadius();
};

#endif //HOROSHOEDITOR_QLINEARAVERAGINGFILTRATIONWINDOW_H
