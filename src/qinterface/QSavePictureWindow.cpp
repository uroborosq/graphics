#include "QSavePictureWindow.h"
#include "Pnm.h"

QSavePictureWindow::QSavePictureWindow(std::string path) {

    this->resize(250, 100);
    auto savePathLine = new QLineEdit();
    savePathLine->setText("enter path to save the file...");
    auto saveButton = new QPushButton("Сохранить");
    saveButton->setFixedSize(100, 30);

    auto layout = new QVBoxLayout();
    layout->addWidget(savePathLine);
    layout->addWidget(saveButton);
    setLayout(layout);

    connect(saveButton, &QPushButton::clicked, this, [=]() {

        auto savePicturePath = savePathLine->text().toStdString();
        Pnm file(path);
        file.write(savePicturePath);

        this->close();
    });
}