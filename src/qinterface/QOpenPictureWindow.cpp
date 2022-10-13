#include <iostream>
#include <string>
#include "QOpenPictureWindow.h"
#include "QImageWidget.h"
#include "Pnm.h"
#include "QMainWindow.h"


QOpenPictureWindow::QOpenPictureWindow() {
    this->resize(200, 100);

    auto label = new QLabel("Введите путь к файлу");
    auto picturePath = new QLineEdit();
    auto openButton = new QPushButton("Открыть");
    auto layout = new QVBoxLayout();

    layout->addWidget(label);
    layout->addWidget(picturePath);
    layout->addWidget(openButton);

    setLayout(layout);

    connect(openButton, &QPushButton::clicked, [=]() {
        this->close();
        auto path = picturePath->text().toStdString();
        auto mainInterface = new QMainWindow(path);
        mainInterface->show();
    });
}