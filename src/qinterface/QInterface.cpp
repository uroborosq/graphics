#include "../../include/qinterface/QInterface.h"
#include "QImageWidget.h"

QInterface::QInterface() {

    this->resize(400, this->height());
    auto picturePath = new QLineEdit();

    auto openButton = new QPushButton("Open");
    openButton->setFixedSize(100, 30);

    auto openLayout = new QVBoxLayout();
    openLayout->addWidget(picturePath);
    openLayout->addWidget(openButton);
    setLayout(openLayout);


    connect(openButton, &QPushButton::clicked, this, [=]() {
        openButton->setText("clicked");
        this->close();
    });

}