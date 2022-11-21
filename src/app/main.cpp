#include <QApplication>
#include "QMain.h"
#include "Pixels.h"
#include "QImageWidget.h"
#include "Ordered8x8Dithering.h"
#include "RandomDithering.h"
#include "FloydSteinbergDithering.h"
#include "AtkinsonDithering.h"
#include <map>



int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    //Pnm file("5.pnm");
    //auto pixels = new Pixels(file.data, file.width, file.height, file.tag, ColorSpace::RGB, ColorChannel::All, 0);
    auto pixels = new Pixels;
    //pixels->setDithering(Dithering::Atkinson, 1);
    auto widget = new QImageWidget(pixels);
    auto interface = QMain(pixels, widget);
    interface.show();
    return QApplication::exec();
}

