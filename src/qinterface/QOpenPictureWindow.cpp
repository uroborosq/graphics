#include <string>
#include <QMessageBox>
#include "QOpenPictureWindow.h"
#include "QImageWidget.h"
#include "QMain.h"


QOpenPictureWindow::QOpenPictureWindow() {
    isSubmitted = false;
    this->resize(200, 100);
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
    isSubmitted = true;
    this->close();
}

void QOpenPictureWindow::findPicture() {

    QString filename =  QFileDialog::getOpenFileName(
            this,
            "Open Document",
            QDir::currentPath(),
            "All files (*.*) ;; PPM files (*.ppm);; PNM files (*.pnm);; PNG files (*.png);;");

    auto pathText = (QLineEdit*)layout()->itemAt(1)->widget();
    pathText->setText(filename);
}

std::string QOpenPictureWindow::getPicturePath() {
    return picturePath->text().toStdString();
}

bool QOpenPictureWindow::checkSubmitted()
{
    return isSubmitted;
}

ColorSpace QOpenPictureWindow::getColorSpace() {
    return ColorSpace(colorspaces->currentIndex());
}



