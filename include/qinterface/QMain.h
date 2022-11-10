#ifndef HOROSHOEDITOR_QMAIN_H
#define HOROSHOEDITOR_QMAIN_H

#include <QWidget>
#include <QApplication>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include "Pnm.h"
#include "QChangeColorspaceWindow.h"

class QMain : public QMainWindow {
public:
    QMain(Pnm* file);
};

#endif //HOROSHOEDITOR_QMAIN_H
