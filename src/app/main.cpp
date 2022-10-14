#include <iostream>
#include <random>
#include <QApplication>
#include "QImageWidget.h"
#include "QOpenPictureWindow.h"
#include "Pnm.h"


int main(int argc, char* argv[]) {

    QApplication app(argc, argv);
    Pnm* file = new Pnm();
    auto interface = new QOpenPictureWindow(file);
    interface->show();

    return QApplication::exec();
}
