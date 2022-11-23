#ifndef HOROSHOEDITOR_QDRAWLINEWINDOW_H
#define HOROSHOEDITOR_QDRAWLINEWINDOW_H

#include <QDialog>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QEvent>
#include <QMouseEvent>
#include <QWidget>
#include "QImageWidget.h"
#include "Pixels.h"
#include "QMain.h"

class QDrawLineWindow : public QWidget {
private:
    QLabel* firstPointXValue;
    QLabel* firstPointYValue;
    QLabel* secondPointXValue;
    QLabel* secondPointYValue;
    Pixels* _pixels;
    QImageWidget* _picture;
    QMain* _mainWindow;
    QColor _color;
    int _lineThickness;
    float _lineTransparency;
    void drawLine();
    void chooseFirstPoint();
    void chooseSecondPoint();

public:
    QDrawLineWindow(Pixels*, QImageWidget*, QMain*, QColor, int, float);
};

#endif //HOROSHOEDITOR_QDRAWLINEWINDOW_H
