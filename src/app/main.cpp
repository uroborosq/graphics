#include <QApplication>
#include "QMain.h"
#include "Pixels.h"
#include "QImageWidget.h"
#include "Png.h"
#include <iostream>
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    auto *pixels = new Pixels();
    auto interface = new QMain(pixels, nullptr);
    interface->show();
    return QApplication::exec();
}

