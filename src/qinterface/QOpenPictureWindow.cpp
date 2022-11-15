#include <iostream>
#include <string>
#include <QMessageBox>
#include "QOpenPictureWindow.h"
#include "QImageWidget.h"
#include "Pnm.h"
#include "QMain.h"


QOpenPictureWindow::QOpenPictureWindow(Pixels* pixels_, QMain* mainWindow_) {
    this->resize(200, 100);
    pixels = pixels_;
    mainWindow = mainWindow_;
    auto pathLabel = new QLabel("Введите путь к файлу");
    picturePath = new QLineEdit();
    auto browseButton = new QPushButton("Найти файл");
    auto openButton = new QPushButton("Открыть");
    openButton->setAutoDefault(true);

    auto colorspaceLabel = new QLabel("Выберите цветовое пространство изображения");
    colorspaces = new QComboBox();
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
    layout->addWidget(browseButton);

    layout->addWidget(colorspaceLabel);
    layout->addWidget(colorspaces);

    layout->addWidget(openButton);

    setLayout(layout);

    connect(browseButton, &QPushButton::clicked, this, &QOpenPictureWindow::findPicture);
    connect(openButton, &QPushButton::clicked, this, &QOpenPictureWindow::openPicture);
}

void QOpenPictureWindow::openPicture() {
    auto path = picturePath->text().toStdString();
    try {
        auto file = Pnm(path);
        auto colorspaceChoice = ColorSpace(colorspaces->currentIndex());
        auto oldPicture = mainWindow->centralWidget();
        *pixels = Pixels(file.data, file.width, file.height, file.tag, colorspaceChoice, ColorChannel::Все);
        auto picture = new QImageWidget(pixels);
        mainWindow->setCentralWidget(picture);

        delete oldPicture;
        this->close();
    }
    catch (const std::invalid_argument &e) {
        auto messageBox = new QMessageBox();
        messageBox->setText(e.what());
        messageBox->exec();
    }
}

void QOpenPictureWindow::findPicture() {

    QString filename =  QFileDialog::getOpenFileName(
            this,
            "Open Document",
            QDir::currentPath(),
            "PNM files (*.pnm)");

    if( !filename.isNull() )
    {
        qDebug() << "selected file path : " << filename.toUtf8();
    }

    auto pathText = (QLineEdit*)layout()->itemAt(1)->widget();
    pathText->setText(filename);
}

