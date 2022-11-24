#include "QGradientGenerationWindow.h"
#include "Gradient.h"

QGradientGenerationWindow::QGradientGenerationWindow(int fileWidth, int fileHeight) {
    isSubmitted = false;
    this->resize(200, 100);

    width = fileWidth;
    height = fileHeight;

    auto layout = new QVBoxLayout();
    auto leftColorTextLabel = new QLabel("Выберите цвет начала градиента");
    leftColorLabel = new QLabel();
    auto changeLeftColorButton = new QPushButton("Поменять цвет");
    auto rightColorTextLabel = new QLabel("Выберите цвет конца градиента");
    rightColorLabel = new QLabel();
    auto changeRightColorButton = new QPushButton("Поменять цвет");
    auto okButton = new QPushButton("Построить градиент");

    leftColorLabel->setStyleSheet("QLabel { background-color :"+leftColor.name()+" }");
    rightColorLabel->setStyleSheet("QLabel { background-color :"+rightColor.name()+" }");

    layout->addWidget(leftColorTextLabel);
    layout->addWidget(leftColorLabel);
    layout->addWidget(changeLeftColorButton);
    layout->addWidget(rightColorTextLabel);
    layout->addWidget(rightColorLabel);
    layout->addWidget(changeRightColorButton);
    layout->addWidget(okButton);

    setLayout(layout);

    connect(changeLeftColorButton, &QPushButton::clicked, this, &QGradientGenerationWindow::changeLeftColor);
    connect(changeRightColorButton, &QPushButton::clicked, this, &QGradientGenerationWindow::changeRightColor);
    connect(okButton, &QPushButton::clicked, this, &QGradientGenerationWindow::generateGradientPicture);
}

bool QGradientGenerationWindow::checkSubmitted()
{
    return isSubmitted;
}

void QGradientGenerationWindow::changeLeftColor() {
    leftColor = QColorDialog::getColor(leftColor, this );
    leftColorLabel->setStyleSheet("QLabel { background-color :"+leftColor.name()+" }");
}

void QGradientGenerationWindow::changeRightColor() {
    rightColor = QColorDialog::getColor(rightColor, this );
    rightColorLabel->setStyleSheet("QLabel { background-color :"+rightColor.name()+" }");
}

void QGradientGenerationWindow::generateGradientPicture() {
    std::vector<float>leftColorVector{static_cast<float>(leftColor.red()),
                                      static_cast<float>(leftColor.green()),
                                      static_cast<float>(leftColor.blue())};
    std::vector<float>rightColorVector{static_cast<float>(rightColor.red()),
                                      static_cast<float>(rightColor.green()),
                                      static_cast<float>(rightColor.blue())};
    Gradient *gradient = new Gradient();
    const char* tag = "56";
    auto values = gradient->drawGradient(width, height, leftColorVector, rightColorVector);
    pixels = new Pixels(values, width, height, tag, ColorSpace::RGB, ColorChannel::All, 0);
    auto picture = new QImageWidget(pixels, nullptr);
    picture->show();
    this->close();
}