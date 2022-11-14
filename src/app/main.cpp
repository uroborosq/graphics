#include <iostream>
#include <QApplication>
#include "QOpenPictureWindow.h"
#include "Pnm.h"
#include "QMain.h"
#include "Pixels.h"
#include "QImageWidget.h"

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    Pixels* pixels = new Pixels();

    auto interface = new QMain(pixels);
    interface->show();

    return QApplication::exec();

}
