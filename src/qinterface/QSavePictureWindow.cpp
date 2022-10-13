#include "QSavePictureWindow.h"
#include "Pnm.h"

QSavePictureWindow::QSavePictureWindow(const std::string& path) {

    this->resize(250, 100);
    auto savePathLine = new QLineEdit();
    auto label = new QLabel("Введите путь для сохранения файла");
    auto saveButton = new QPushButton("Сохранить");

    auto layout = new QVBoxLayout();
    layout->addWidget(label);
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