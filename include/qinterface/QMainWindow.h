#ifndef HOROSHOEDITOR_QMAINWINDOW_H
#define HOROSHOEDITOR_QMAINWINDOW_H

#include <QWidget>
#include <QApplication>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include "Pnm.h"
class QMainWindow : public QWidget {
public:
    QMainWindow(Pnm* file);
};

#endif //HOROSHOEDITOR_QMAINWINDOW_H
