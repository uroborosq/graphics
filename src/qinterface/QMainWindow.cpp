#include "QMainWindow.h"
#include "QImageWidget.h"
#include "QSavePictureWindow.h"
#include "Pnm.h"

QMainWindow::QMainWindow(Pnm* file){

    this->resize(200, 300);

    auto saveButton = new QPushButton("Сохранить как...");

    auto picture = new QImageWidget(file->data, file->height, file->width, file->tag);

    auto layout = new QVBoxLayout();
    layout->addWidget(picture);
    layout->addWidget(saveButton);
    setLayout(layout);

    connect(saveButton, &QPushButton::clicked, this, [=]() {
        auto saveWindow = new QSavePictureWindow(file);
        saveWindow->show();
    });

}