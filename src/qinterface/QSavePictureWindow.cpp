#include <QMessageBox>
#include "QSavePictureWindow.h"
#include "Pnm.h"
#include "selectcolorchannel.h"

QSavePictureWindow::QSavePictureWindow(Pixels* pixels) {

    this->resize(250, 100);
    auto savePathLine = new QLineEdit();
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

void QSavePictureWindow::savePicture() {
    auto savePicturePath = savePathLine->text().toStdString();
    try {
        Pnm file;
        file.width = pixels->getWidth();
        file.height = pixels->getHeight();
        file.max = 255;
        file.tag[0] = 'P';
        if (pixels->getTag() == PnmFormat::P5)
            file.tag[1] = '5';
        else {
            if (pixels->getColorChannel() == ColorChannel::Все)
                file.tag[1] = '6';
            else
                file.tag[1] = '5';
        }

        file.data = *remove_other_channels(pixels->getValues(), pixels->getColorChannel());
        file.write(savePicturePath);
        this->close();
    }
    catch (const std::invalid_argument& e){
        auto box = new QMessageBox();
        box->setText(e.what());
        box->exec();
    }
}