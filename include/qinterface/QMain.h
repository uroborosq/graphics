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
#include <QMessageBox>
#include "Pnm.h"
#include "Pixels.h"
#include "QImageWidget.h"

class QMain : public QMainWindow {
private:
    Pixels* pixels;
    QImageWidget* picture;

public:
    QMain(Pixels*, QImageWidget*);
    void openOpenWindow();
    void openSaveWindow();
    void openColorSpaceAndChannelWindow();
    void openAssignGammaWindow();
    void openConvertGammaWindow();
    void openDrawLineWindow();
    void openLineParametersWindow();
};

#endif //HOROSHOEDITOR_QMAIN_H
