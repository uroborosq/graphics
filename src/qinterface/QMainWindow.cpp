#include "QMainWindow.h"
#include "QImageWidget.h"
#include "QSavePictureWindow.h"

QMainWindow::QMainWindow(std::vector<uint8_t> pixels, const int& height, const int& width, char* tag){

    this->resize(200, 300);

    auto saveButton = new QPushButton("Save as...");
    saveButton->setFixedSize(100, 30);

    auto picture = new QImageWidget(pixels, height, width, tag);

    auto layout = new QVBoxLayout();
    layout->addWidget(picture);
    layout->addWidget(saveButton);
    setLayout(layout);

    this->show();

    connect(saveButton, &QPushButton::clicked, this, [=]() {
        auto saveWindow = new QSavePictureWindow();
        saveWindow->show();
    });

}