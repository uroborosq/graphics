#include "QChangeColorspaceWindow.h"
#include "QImageWidget.h"

QChangeColorspaceWindow::QChangeColorspaceWindow(const ColorSpace& currentColorSpace,
        const ColorChannel& currentColorChannel) {
    this->resize(200, 100);
    isSubmitted = false;
    auto colorspaceLabel = new QLabel("Выберите цветовое пространство изображения");
    colorspaces = new QComboBox();
    colorspaces->addItem("RGB");
    colorspaces->addItem("HSL");
    colorspaces->addItem("HSV");
    colorspaces->addItem("YCbCr.601");
    colorspaces->addItem("YCbCr.709");
    colorspaces->addItem("YCbCg");
    colorspaces->addItem("CMY");

    auto colorchannelLabel = new QLabel("Выберите цветовой канал");
    auto colorchannels = changeColorChannelBox(currentColorSpace, currentColorChannel);

    colorspaces->setCurrentIndex(currentColorSpace);
    colorchannels->setCurrentIndex(currentColorChannel);
    auto confirmButton = new QPushButton("Выбрать");
    confirmButton->setAutoDefault(true);

    auto layout = new QVBoxLayout();

    layout->addWidget(colorspaceLabel);
    layout->addWidget(colorspaces);

    layout->addWidget(colorchannelLabel);
    layout->addWidget(colorchannels);

    layout->addWidget(confirmButton);

    setLayout(layout);

    connect(colorspaces, &QComboBox::currentIndexChanged,[=](int index){
        auto channels = layout->itemAt(3)->widget();
        layout->removeWidget(channels);
        delete channels;
        layout->insertWidget(3, changeColorChannelBox(index, currentColorChannel));
    });

    connect(confirmButton, &QPushButton::clicked, this, &QChangeColorspaceWindow::changeColorSpace);
}

QComboBox* QChangeColorspaceWindow::changeColorChannelBox(int index, const ColorChannel& currentColorChannel) {

    auto newChannels = new QComboBox();
    newChannels->addItem("All");

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


    return newChannels;
}

void QChangeColorspaceWindow::changeColorSpace() {
    isSubmitted = true;
    this->close();
}

ColorSpace QChangeColorspaceWindow::getColorSpace() {
    return ColorSpace(colorspaces->currentIndex());
}

ColorChannel QChangeColorspaceWindow::getColorChannel() {
    return ColorChannel(((QComboBox*)layout()->itemAt(3)->widget())->currentIndex());
}

bool QChangeColorspaceWindow::checkSubmitted()
{
    return isSubmitted;
}