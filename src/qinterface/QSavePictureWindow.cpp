#include "QSavePictureWindow.h"
#include "QImageWidget.h"

QSavePictureWindow::QSavePictureWindow() {

    this->resize(250, 100);
    auto savePathLine = new QLineEdit();
    savePathLine->setText("enter path to save the file...");
    auto saveButton = new QPushButton("Save");
    saveButton->setFixedSize(100, 30);

    auto layout = new QVBoxLayout();
    layout->addWidget(savePathLine);
    layout->addWidget(saveButton);
    setLayout(layout);

    connect(saveButton, &QPushButton::clicked, this, [=]() {

        auto savePicturePath = savePathLine->text().toStdString();
        this->close();
    });
}