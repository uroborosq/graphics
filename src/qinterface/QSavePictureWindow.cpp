#include <QMessageBox>
#include "QSavePictureWindow.h"
#include "Pnm.h"

QSavePictureWindow::QSavePictureWindow(Pnm* file) {

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
        try {
            auto savePicturePath = savePathLine->text().toStdString();
            file->write(savePicturePath);
            this->close();
        }
        catch (const std::invalid_argument& e){
            auto box = new QMessageBox();
            box->setText(e.what());
            box->exec();
        }
    });
}