#include <QApplication>
#include "QMain.h"
#include "Pixels.h"
#include "QImageWidget.h"
#include "Ordered8x8Dithering.h"
#include <map>



int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Pnm file("2.pnm");

    std::map<float, int> counter;
    file.data = Ordered8x8Dithering().proceed(file.data, file.width, 1);
    for (float &c: file.data)
        std::cout << c << std::endl;
    auto pixels = new Pixels(file.data, file.width, file.height, file.tag, ColorSpace::RGB, ColorChannel::All, 0);
    auto widget = new QImageWidget(pixels);
    auto interface = QMain(pixels, widget);
    interface.show();
    return QApplication::exec();
}

