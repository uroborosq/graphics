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

class QMain : public QMainWindow {
private:
    Pixels* pixels;

public:
    QMain(Pixels*);
    void openOpenWindow();
    void openSaveWindow();
    void openColorSpaceAndChannelWindow();
    void openAssignGammaWindow();
    void openConvertGammaWindow();
};

#endif //HOROSHOEDITOR_QMAIN_H
