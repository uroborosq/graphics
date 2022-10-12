#include <iostream>
#include <random>
#include <QApplication>
#include "QImageWidget.h"
#include "../../include/qinterface/QInterface.h"


int main(int argc, char* argv[]) {
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    std::default_random_engine e;
    QApplication app(argc, argv);

    auto interface = new QInterface();
    interface->show();
    return QApplication::exec();
}
