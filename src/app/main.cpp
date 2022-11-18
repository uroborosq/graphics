#include <QApplication>
#include "QMain.h"
#include "Pixels.h"
#include "GammaCorrection.h"
#include "QImageWidget.h"

int main(int argc, char *argv[]) {
//    QApplication app(argc, argv);
//    auto* pixels = new Pixels();
//
//    auto interface = new QMain(pixels);
//    interface->show();
//
//    return QApplication::exec();
    QApplication app(argc, argv);
    Pnm *file = new Pnm("2.pnm");

    auto pixels = new Pixels(file->data, file->width, file->height, file->tag, ColorSpace(0),ColorChannel(0), 1 / 2.2);

    pixels->setGamma(0.25);

    auto widget = QImageWidget(pixels);
    widget.setGamma(3);

    widget.show();


    widget.show();

    return QApplication::exec();
}
