#include <iostream>
#include <QApplication>
#include "QOpenPictureWindow.h"
#include "Pnm.h"
#include "QMain.h"
#include "Pixels.h"
#include "QImageWidget.h"
#include "HSVColorSpace.h"
int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

//    auto* pixels = new Pixels();
//
//    auto interface = new QMain(pixels);
//    interface->show();


    Pnm file("1.pnm");
//    pixels.setColorSpace(ColorSpace::HSV);

    auto converter = HSVColorSpace();
    file.data = converter.from_rgb(file.data);
    file.data = converter.to_rgb(file.data);
    Pixels pixels(file.data, file.height, file.width, file.tag, ColorSpace::RGB, ColorChannel::Все);


  auto widget = QImageWidget(&pixels);
 widget.show();
    return QApplication::exec();

}
