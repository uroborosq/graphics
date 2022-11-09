#include <iostream>
#include <QApplication>
#include "QOpenPictureWindow.h"
#include "Pnm.h"
#include <iostream>
#include "HSVColorSpace.h"
#include "CMYColorSpace.h"
#include "selectcolorchannel.h"
#include "QImageWidget.h"
#include "HSLColorSpace.h"
#include "YCoCgColorSpace.h"
#include "YCbCr_601ColorSpace.h"
#include "YCbCr_709ColorSpace.h"

int main(int argc, char *argv[]) {
//// Можно потестить этим
//    QApplication app(argc, argv);
//    Pnm *file = new Pnm(R"(C:\Progi\project-horosho\cg22-project-horosho\sample1.pnm)");
//    auto data = file->data;
//
//    auto hsl = YCbCr_709ColorSpace();
//
//    hsl.from_rgb(data);
//
//    auto filtered_data = select_color_channel(data, 3);
//
//    hsl.to_rgb(*filtered_data);
//
//    auto widget = QImageWidget(*filtered_data, file->height, file->width, file->tag);
//    widget.show();
//
//    std::cout << std::endl;
//
//
//    return QApplication::exec();


    QApplication app(argc, argv);
    Pnm* file = new Pnm();
    auto interface = new QOpenPictureWindow(file);
    interface->show();

    return QApplication::exec();

}
