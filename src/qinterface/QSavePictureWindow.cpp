#include <QMessageBox>
#include "QSavePictureWindow.h"
#include "Pnm.h"

QSavePictureWindow::QSavePictureWindow(Pnm* file) {

    this->resize(250, 100);
    auto savePathLine = new QLineEdit();
    auto saveLabel = new QLabel("Введите путь для сохранения файла");
    auto saveButton = new QPushButton("Сохранить");
    saveButton->setAutoDefault(true);

    auto colorspaceLabel = new QLabel("Выберите цветовое пространство изображения");
    auto colorspaces = new QComboBox();
    colorspaces->addItem("RGB");
    colorspaces->addItem("HSL");
    colorspaces->addItem("HSV");
    colorspaces->addItem("YCbCr.601");
    colorspaces->addItem("YCbCr.709");
    colorspaces->addItem("YCbCg");
    colorspaces->addItem("CMY");

    auto layout = new QVBoxLayout();
    layout->addWidget(saveLabel);
    layout->addWidget(savePathLine);

    layout->addWidget(colorspaceLabel);
    layout->addWidget(colorspaces);

    layout->addWidget(saveButton);
    setLayout(layout);

    connect(saveButton, &QPushButton::clicked, this, [=]() {
        try {
            auto colorspaceChoice = colorspaces->currentIndex();
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