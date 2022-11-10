#include "QChangeColorspaceWindow.h"

QChangeColorspaceWindow::QChangeColorspaceWindow() {
    this->resize(200, 100);

    auto colorspaceLabel = new QLabel("Выберите цветовое пространство изображения");
    auto colorspaces = new QComboBox();
    colorspaces->addItem("RGB");
    colorspaces->addItem("HSL");
    colorspaces->addItem("HSV");
    colorspaces->addItem("YCbCr.601");
    colorspaces->addItem("YCbCr.709");
    colorspaces->addItem("YCbCg");
    colorspaces->addItem("CMY");

    auto colorchannelLabel = new QLabel("Выберите цветовой канал");
    auto colorchannels = new QComboBox();
    colorchannels->addItem("Все");
    colorchannels->addItem("R");
    colorchannels->addItem("G");
    colorchannels->addItem("B");

    auto confirmButton = new QPushButton("Выбрать");
    confirmButton->setAutoDefault(true);

    auto layout = new QVBoxLayout();

    layout->addWidget(colorspaceLabel);
    layout->addWidget(colorspaces);

    layout->addWidget(colorchannelLabel);
    layout->addWidget(colorchannels);

    layout->addWidget(confirmButton);

    setLayout(layout);

    connect(colorspaces, QOverload<int>::of(&QComboBox::currentIndexChanged),[=](int index){
        auto channels = layout->itemAt(3)->widget();
        layout->removeWidget(channels);
        delete channels;
        auto newChannels = new QComboBox();
        newChannels->addItem("Все");

        // RGB
        if (index == 0) {
            newChannels->addItem("R");
            newChannels->addItem("G");
            newChannels->addItem("B");
        }

        // HSL
        if (index == 1) {
            newChannels->addItem("H");
            newChannels->addItem("S");
            newChannels->addItem("L");
        }

        // HSV
        if (index == 2) {
            newChannels->addItem("H");
            newChannels->addItem("S");
            newChannels->addItem("V");
        }

        // YCbCr.601
        if (index == 3) {
            newChannels->addItem("Y");
            newChannels->addItem("Cb");
            newChannels->addItem("Cr");
        }

        // YCbCr.709
        if (index == 4) {
            newChannels->addItem("Y");
            newChannels->addItem("Cb");
            newChannels->addItem("Cr");
        }

        // YCbCg
        if (index == 5) {
            newChannels->addItem("Y");
            newChannels->addItem("Cb");
            newChannels->addItem("Cg");
        }

        // CMY
        if (index == 6) {
            newChannels->addItem("C");
            newChannels->addItem("M");
            newChannels->addItem("Y");
        }

        layout->insertWidget(3, newChannels);
    });

    connect(confirmButton, &QPushButton::clicked, [=]() {
        this->close();
        delete this;
    });
}