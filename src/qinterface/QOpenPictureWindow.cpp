#include <iostream>
#include <string>
#include <QMessageBox>
#include "QOpenPictureWindow.h"
#include "QImageWidget.h"
#include "Pnm.h"
#include "QMain.h"


QOpenPictureWindow::QOpenPictureWindow(Pnm *file, QMain* mainWindow) {
    this->resize(200, 100);

    auto pathLabel = new QLabel("Введите путь к файлу");
    auto picturePath = new QLineEdit();
    auto openButton = new QPushButton("Открыть");
    openButton->setAutoDefault(true);

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

    layout->addWidget(pathLabel);
    layout->addWidget(picturePath);

    layout->addWidget(colorspaceLabel);
    layout->addWidget(colorspaces);

    layout->addWidget(openButton);

    setLayout(layout);

    connect(openButton, &QPushButton::clicked, [=]() {
        auto path = picturePath->text().toStdString();
        try {
            file->read(path);
            auto colorspaceChoice = colorspaces->currentText();
            auto oldPicture = mainWindow->centralWidget();
//            auto picture = new QImageWidget(file->data, file->height, file->width, file->tag);
//            mainWindow->setCentralWidget(picture);
            delete oldPicture;
            this->close();
        }
        catch (const std::invalid_argument &e) {
            auto messageBox = new QMessageBox();
            messageBox->setText(e.what());
            messageBox->exec();
        }
    });
}
