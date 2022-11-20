#include <QApplication>
#include "QMain.h"
#include "Pixels.h"
#include "QImageWidget.h"
#include "sRGBColorSpace.h"
#include "DrawColoredLine.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Pnm file ("2.pnm");
    auto* pixels = new Pixels(file.data, file.width, file.height, file.tag);
    std::vector<float>color{255, 1, 2};
    auto drawer = new DrawColoredLine();
    pixels->drawLine(drawer, 0, 0, 100, 100, color, 30, 0);
    auto* picture = new QImageWidget(pixels);
    auto interface = new QMain(pixels, picture);
    interface->show();
    return QApplication::exec();
}
