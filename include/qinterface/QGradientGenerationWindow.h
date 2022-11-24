#ifndef HOROSHOEDITOR_QGRADIENTGENERATIONWINDOW_H
#define HOROSHOEDITOR_QGRADIENTGENERATIONWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QColor>
#include <QVBoxLayout>
#include <QColorDialog>
#include "QImageWidget.h"

class QGradientGenerationWindow : public QWidget {
private:
    bool isSubmitted;
    int width;
    int height;
    QColor leftColor = Qt::red;
    QColor rightColor = Qt::red;
    QLabel* leftColorLabel;
    QLabel* rightColorLabel;
    Pixels *pixels;
    QImageWidget *picture;
    void changeLeftColor();
    void changeRightColor();
    void setDithering();
    void generateGradientPicture();

public:
    QGradientGenerationWindow(int, int);
    bool checkSubmitted();
};

#endif //HOROSHOEDITOR_QGRADIENTGENERATIONWINDOW_H
