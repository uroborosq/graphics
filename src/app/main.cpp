#include <iostream>
#include <random>
#include <QApplication>
#include "QImageWidget.h"
#include "QOpenPictureWindow.h"
#include "Pnm.h"


int main(int argc, char* argv[]) {

    QApplication app(argc, argv);

//    Pnm file("logo.pnm");

    auto interface = new QOpenPictureWindow();
    interface->show();

    return QApplication::exec();
//    return 0;
}
