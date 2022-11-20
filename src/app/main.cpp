#include <QApplication>
#include "QMain.h"
#include "Pixels.h"
#include "QImageWidget.h"
#include "sRGBColorSpace.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    auto* pixels = new Pixels();
    auto* picture = new QImageWidget(pixels);
    auto interface = new QMain(pixels, picture);
    interface->show();
    return QApplication::exec();
}
