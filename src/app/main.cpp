#include <QApplication>
#include "QMain.h"
#include "Pixels.h"
#include "QImageWidget.h"
#include "Ordered8x8Dithering.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Pnm file("2.pnm");

    file.data = Ordered8x8Dithering().proceed(file.data, file.width, file.height);

    auto pixels = new Pixels(file.data, file.width, file.height, file.tag, ColorSpace::RGB, ColorChannel::All, 0);



    auto interface = new QMain(pixels, new QImageWidget(pixels));
    interface->show();
    return QApplication::exec();
}
