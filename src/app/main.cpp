#include <iostream>
#include <QApplication>
#include "QOpenPictureWindow.h"
#include "Pnm.h"
#include "QMain.h"
#include "Pixels.h"
#include "QImageWidget.h"

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    Pnm* file = new Pnm("1.pnm");

    auto* pixels = new Pixels(file->data, file->width, file->height, file->tag, ColorSpace::RGB, ColorChannel::Все);

//    auto interface = new QMain(file);
//    interface->show();
    pixels->setColorSpace(ColorSpace::CMY);
    pixels->setColorChannel(ColorChannel::Третий);
    auto* widget = new QImageWidget(pixels);
    widget->show();
    return QApplication::exec();

}
