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

class QDrawLineWindow : public QWidget {
private:
    QLabel* firstPointXValue;
    QLabel* firstPointYValue;
    QLabel* secondPointXValue;
    QLabel* secondPointYValue;
    QImageWidget* _picture;
    void drawLine();
    void chooseFirstPoint();
    void chooseSecondPoint();

public:
    QDrawLineWindow(QImageWidget*);
};

#endif //HOROSHOEDITOR_QDRAWLINEWINDOW_H
