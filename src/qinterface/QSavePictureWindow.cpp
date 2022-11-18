#include <QMessageBox>
#include "QSavePictureWindow.h"
#include "Pnm.h"
#include "selectcolorchannel.h"

QSavePictureWindow::QSavePictureWindow() {

    isSubmitted = false;
    this->resize(250, 100);

    savePathLine = new QLineEdit();
    auto saveLabel = new QLabel("Введите путь для сохранения файла");
    auto saveButton = new QPushButton("Сохранить");
    saveButton->setAutoDefault(true);

    auto layout = new QVBoxLayout();
    layout->addWidget(saveLabel);
    layout->addWidget(savePathLine);

    layout->addWidget(saveButton);
    setLayout(layout);

    connect(saveButton, &QPushButton::clicked, this, &QSavePictureWindow::savePicture);
}

bool QSavePictureWindow::checkSubmitted() {
    return isSubmitted;
}

void QSavePictureWindow::savePicture() {
    isSubmitted = true;
    this->close();
}

std::string QSavePictureWindow::getPicturePath() {
    return savePathLine->text().toStdString();
}
