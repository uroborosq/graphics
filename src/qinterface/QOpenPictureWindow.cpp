#include <iostream>
#include <string>
#include "QOpenPictureWindow.h"
#include "QImageWidget.h"
#include "Pnm.h"
#include "QMainWindow.h"


QOpenPictureWindow::QOpenPictureWindow() {

    this->resize(200, 100);
    auto picturePath = new QLineEdit();
    picturePath->setText("enter path to the file...");

    auto openButton = new QPushButton("Открыть");
    openButton->setFixedSize(100, 30);

    auto layout = new QVBoxLayout();
    layout->addWidget(picturePath);
    layout->addWidget(openButton);
    setLayout(layout);


    connect(openButton, &QPushButton::clicked, [=]() {

        this->close();

        auto path = picturePath->text().toStdString();

        auto mainInterface = new QMainWindow(path);

    });
}