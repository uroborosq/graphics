#include <QSpinBox>
#include "QGradientGenerationWindow.h"
#include "Gradient.h"
#include "QDitheringParametersWindow.h"

QGradientGenerationWindow::QGradientGenerationWindow(int fileWidth, int fileHeight) {
    isSubmitted = false;
    this->resize(200, 100);

    pixels = nullptr;
    picture = nullptr;
    widthBox = new QSpinBox();
    heightBox = new QSpinBox();
    widthBox->setMaximum(100000);
    heightBox->setMaximum(100000);
    widthBox->setValue(fileWidth == 0 ? 1600 : fileWidth);
    heightBox->setValue(fileHeight == 0 ? 900 : fileHeight);
    auto layout = new QVBoxLayout();
    auto leftColorTextLabel = new QLabel("Выберите цвет начала градиента");
    leftColorLabel = new QLabel();
    auto changeLeftColorButton = new QPushButton("Поменять цвет");
    auto rightColorTextLabel = new QLabel("Выберите цвет конца градиента");
    rightColorLabel = new QLabel();
    auto changeRightColorButton = new QPushButton("Поменять цвет");
    gradientButton = new QPushButton("Показать превью");
    auto ditheringButton = new QPushButton("Дизеринг");
    auto grayscaleGradientButton = new QPushButton("Построить черно-белый градиент от 0 до 255");
    auto submit = new QPushButton("Подтвердить");

    leftColorLabel->setStyleSheet("QLabel { background-color :" + leftColor.name() + " }");
    rightColorLabel->setStyleSheet("QLabel { background-color :" + rightColor.name() + " }");

    layout->addWidget(leftColorTextLabel);
    layout->addWidget(leftColorLabel);
    layout->addWidget(changeLeftColorButton);
    layout->addWidget(rightColorTextLabel);
    layout->addWidget(rightColorLabel);
    layout->addWidget(changeRightColorButton);
    layout->addWidget(widthBox);
    layout->addWidget(heightBox);
    layout->addWidget(ditheringButton);
    layout->addWidget(gradientButton);
    layout->addWidget(grayscaleGradientButton);
    layout->addWidget(submit);

    setLayout(layout);

    connect(changeLeftColorButton, &QPushButton::clicked, this, &QGradientGenerationWindow::changeLeftColor);
    connect(changeRightColorButton, &QPushButton::clicked, this, &QGradientGenerationWindow::changeRightColor);
    connect(ditheringButton, &QPushButton::clicked, this, &QGradientGenerationWindow::setDithering);
    connect(gradientButton, &QPushButton::clicked, this, &QGradientGenerationWindow::generateGradientPicture);
    connect(grayscaleGradientButton, &QPushButton::clicked, this,
            &QGradientGenerationWindow::generateGrayscaleGradient);
    connect(submit, &QPushButton::clicked, this, &QGradientGenerationWindow::close);

}

bool QGradientGenerationWindow::checkSubmitted() {
    return isSubmitted;
}

void QGradientGenerationWindow::changeLeftColor() {
    leftColor = QColorDialog::getColor(leftColor, this);
    leftColorLabel->setStyleSheet("QLabel { background-color :" + leftColor.name() + " }");
}

void QGradientGenerationWindow::changeRightColor() {
    rightColor = QColorDialog::getColor(rightColor, this);
    rightColorLabel->setStyleSheet("QLabel { background-color :" + rightColor.name() + " }");
}

void QGradientGenerationWindow::setDithering() {
    if (pixels != nullptr) {
        auto ditheringParametersWindow = new QDitheringParametersWindow(pixels, nullptr);
        ditheringParametersWindow->exec();
        delete pixels;
        pixels = ditheringParametersWindow->getDitheringPixels();
        picture->close();
        picture = ditheringParametersWindow->getDitheringPicture();
        picture->show();
    }
};

void QGradientGenerationWindow::generateGradientPicture() {
    if (picture != nullptr) {
        picture->close();
        delete picture;
        picture = nullptr;
        gradientButton->setText("Показать превью");
    } else {
        isSubmitted = true;
        std::vector<float> leftColorVector{static_cast<float>(leftColor.red()),
                                           static_cast<float>(leftColor.green()),
                                           static_cast<float>(leftColor.blue())};
        std::vector<float> rightColorVector{static_cast<float>(rightColor.red()),
                                            static_cast<float>(rightColor.green()),
                                            static_cast<float>(rightColor.blue())};
        auto *gradient = new Gradient();
        const char *tag = "P6";
        auto values = gradient->drawGradient(widthBox->value(), heightBox->value(), leftColorVector, rightColorVector);
        delete pixels;
        pixels = new Pixels(values, widthBox->value(), heightBox->value(), tag, ColorSpace::RGB, ColorChannel::All, 0);
        picture = new QImageWidget(pixels, nullptr);
        gradientButton->setText("Закрыть превью");
        picture->show();
    }
}

void QGradientGenerationWindow::generateGrayscaleGradient() {
    if (picture != nullptr) {
        picture->close();
        delete picture;
        pixels = nullptr;
        gradientButton->setText("Показать превью");
    } else {
        isSubmitted = true;
        std::vector<float> leftColorVector{0};
        std::vector<float> rightColorVector{255};
        auto *gradient = new Gradient();
        const char *tag = "P5";
        auto values = gradient->drawGradient(widthBox->value(), heightBox->value(), leftColorVector, rightColorVector);
        delete pixels;
        pixels = new Pixels(values, widthBox->value(), heightBox->value(), tag, ColorSpace::RGB, ColorChannel::All, 1);
        picture = new QImageWidget(pixels, nullptr);
        gradientButton->setText("Закрыть превью");
        picture->show();
    }
}

Pixels *QGradientGenerationWindow::getGradient() {
    return pixels;
}
