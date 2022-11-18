#include <QApplication>
#include "QMain.h"
#include "Pixels.h"
#include "QImageWidget.h"

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    auto file = new Pnm("3.ppm");

    auto* pixels = new Pixels(file->data, file->width, file->height, file->tag, ColorSpace::RGB, ColorChannel::Все);

 //   auto interface = new QMain(pixels);
//    interface->show();
    auto widget = new QImageWidget(pixels);
    widget->show();
    return QApplication::exec();

}
