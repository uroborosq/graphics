#include "QDitheringParametersWindow.h"
#include "QImageWidget.h"
#include "QMain.h"

QDitheringParametersWindow::QDitheringParametersWindow(Pixels* pixels, QMain* mainWindow) {
    isSubmitted = true;
    this->resize(200, 100);

    _pixels = pixels;
    _ditheringPicture = new QImageWidget(pixels, mainWindow);

    auto layout = new QVBoxLayout();
    auto algorithmLabel = new QLabel("Выберите алгоритм дизеринга");
    algorithmComboBox = new QComboBox();
    auto bitDepthLabel = new QLabel("Выберить битность");
    auto sliderLayout = new QGridLayout();
    bitDepthSlider = new QSlider(Qt::Horizontal);
    bitDepthValue = new QLabel("1");
    auto oneBitLabel = new QLabel("1");
    auto eightBitLabel = new QLabel("8");
    auto previewButton = new QPushButton("Предварительный просмотр");
    auto okButton = new QPushButton("Применить");

    algorithmComboBox->addItem("None");
    algorithmComboBox->addItem("Ordered(8x8)");
    algorithmComboBox->addItem("Random");
    algorithmComboBox->addItem("Floyd-Steinberg");
    algorithmComboBox->addItem("Atkinson");

    bitDepthSlider->setRange(1, 8);
    bitDepthSlider->setValue(1);
    bitDepthSlider->setPageStep(1);

    sliderLayout->addWidget(bitDepthSlider, 0, 0, 1, 1);
    sliderLayout->addWidget(bitDepthValue, 0, 1, 1, 1);
    sliderLayout->addWidget(oneBitLabel, 1, 0, 1, 1);
    sliderLayout->addWidget(eightBitLabel, 1, 1, 1, 1);

    layout->addWidget(algorithmLabel);
    layout->addWidget(algorithmComboBox);
    layout->addWidget(bitDepthLabel);
    layout->addItem(sliderLayout);
    layout->addWidget(previewButton);
    layout->addWidget(okButton);

    setLayout(layout);

    connect(previewButton, &QPushButton::clicked, this, &QDitheringParametersWindow::showPreview);
    connect(okButton, &QPushButton::clicked, this, &QDitheringParametersWindow::setDithering);
    connect(bitDepthSlider, &QSlider::valueChanged, this, &QDitheringParametersWindow::changeBitDepth);

}

void QDitheringParametersWindow::showPreview() {
    auto algorithm = getAlgorithm();
    auto bitDepth = getBitDepth();
    _pixels->setDithering(algorithm, bitDepth);
    delete _ditheringPicture;
    _ditheringPicture = new QImageWidget(_pixels, nullptr);
    _ditheringPicture->show();
}

void QDitheringParametersWindow::setDithering() {
    isSubmitted = true;
    _ditheringPicture->close();
    this->close();
}

void QDitheringParametersWindow::changeBitDepth() {
    bitDepthValue->setText(" " + QString::number(bitDepthSlider->value()) + " бит");
}

Dithering QDitheringParametersWindow::getAlgorithm() {
    return Dithering(algorithmComboBox->currentIndex());
}

int QDitheringParametersWindow::getBitDepth() {
    return bitDepthSlider->value();
}

Pixels* QDitheringParametersWindow::getDitheringPixels() {
    return _pixels;
}

QImageWidget* QDitheringParametersWindow::getDitheringPicture() {
    return _ditheringPicture;
}