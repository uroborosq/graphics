#include "QMainWindow.h"
#include "QImageWidget.h"
#include "QSavePictureWindow.h"
#include "Pnm.h"

QMainWindow::QMainWindow(const std::string& path){

    this->resize(200, 300);

    auto saveButton = new QPushButton("Сохранить как...");

    Pnm file(path);
    auto picture = new QImageWidget(file.data, file.height, file.width, file.tag);

    auto layout = new QVBoxLayout();
    layout->addWidget(picture);
    layout->addWidget(saveButton);
    setLayout(layout);

    connect(saveButton, &QPushButton::clicked, this, [=]() {
        auto saveWindow = new QSavePictureWindow(path);
        saveWindow->show();
    });

}