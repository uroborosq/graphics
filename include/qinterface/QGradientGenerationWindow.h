#ifndef HOROSHOEDITOR_QGRADIENTGENERATIONWINDOW_H
#define HOROSHOEDITOR_QGRADIENTGENERATIONWINDOW_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QColor>
#include <QVBoxLayout>
#include <QColorDialog>
#include "QImageWidget.h"

class QGradientGenerationWindow : public QDialog {
private:
    bool isSubmitted;
    int width;
    int height;
    QColor leftColor = Qt::red;
    QColor rightColor = Qt::red;
    QLabel* leftColorLabel;
    QLabel* rightColorLabel;
    Pixels *pixels;
    void changeLeftColor();
    void changeRightColor();
    void generateGradientPicture();

public:
    QGradientGenerationWindow(int, int);
    bool checkSubmitted();
};

#endif //HOROSHOEDITOR_QGRADIENTGENERATIONWINDOW_H
