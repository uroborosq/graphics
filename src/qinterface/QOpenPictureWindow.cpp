#include <iostream>
#include <string>
#include <QMessageBox>
#include "QOpenPictureWindow.h"
#include "QImageWidget.h"
#include "Pnm.h"
#include "QMainWindow.h"


QOpenPictureWindow::QOpenPictureWindow(Pnm *file) {
    this->resize(200, 100);

    auto label = new QLabel("Введите путь к файлу");
    auto picturePath = new QLineEdit();
    auto openButton = new QPushButton("Открыть");
    openButton->setAutoDefault(true);
    auto layout = new QVBoxLayout();

    layout->addWidget(label);
    layout->addWidget(picturePath);
    layout->addWidget(openButton);

    setLayout(layout);

    connect(openButton, &QPushButton::clicked, [=]() {
        auto path = picturePath->text().toStdString();
        try {
            file->read(path);
            auto mainInterface = new QMainWindow(file);
            this->close();
            mainInterface->show();
        }
        catch (const std::invalid_argument &e) {
            auto messageBox = new QMessageBox();
            messageBox->setText(e.what());
            messageBox->exec();
        }
    });
}