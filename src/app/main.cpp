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
//// Можно потестить этим
    QApplication app(argc, argv);
    Pnm *file = new Pnm(R"(C:\Progi\project-horosho\cg22-project-horosho\sample1.pnm)");
    auto& data = file->data;
    auto gc = GammaCorrection();
    float a = 2;
    float b = 3;
    auto newData = gc.changeGamma(data, a, b);
    auto pixels = Pixels(newData, file->width, file->height, file->tag, ColorSpace(0),ColorChannel(0));
    auto widget = QImageWidget(&pixels);
    widget.show();
    return QApplication::exec();
}
