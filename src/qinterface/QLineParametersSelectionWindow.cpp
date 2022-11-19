#include "QLineParametersSelectionWindow.h"

QLineParametersSelectionWindow::QLineParametersSelectionWindow() {
    isSubmitted = false;
    this->resize(200, 100);

    auto layout = new QVBoxLayout();
    auto currentColorTextLabel = new QLabel("Текущий цвет:");
    colorLabel = new QLabel();
    auto changeColorButton = new QPushButton("Поменять цвет");
    auto lineThicknessTextLabel = new QLabel("Толщина линии (px):");
    lineThicknessValue = new QSpinBox();
    auto lineTransparencyTextLabel = new QLabel("Прозрачность линии:");
    auto sliderLayout = new QGridLayout();
    lineTransparencyValue = new QSlider(Qt::Horizontal);
    auto transparenceZero = new QLabel("0");
    auto transparenceTwo = new QLabel("0.2");
    auto transparenceFour = new QLabel("0.4");
    auto transparenceSix = new QLabel("0.6");
    auto transparenceEight = new QLabel("0.8");
    auto transparenceOne = new QLabel("1");
    auto okButton = new QPushButton("OK");

    colorLabel->setStyleSheet("QLabel { background-color :"+color.name()+" }");

    lineThicknessValue->setValue(1);
    lineThicknessValue->setMinimum(1);

    lineTransparencyValue->setRange(0, 10);
    lineTransparencyValue->setValue(10);
    lineTransparencyValue->setPageStep(1);

    sliderLayout->addWidget(lineTransparencyValue, 0, 0, 1, 10);
    sliderLayout->addWidget(transparenceZero, 1, 0, 1, 1);
    sliderLayout->addWidget(transparenceTwo, 1, 2, 1, 1);
    sliderLayout->addWidget(transparenceFour, 1, 4, 1, 1);
    sliderLayout->addWidget(transparenceSix, 1, 6, 1, 1);
    sliderLayout->addWidget(transparenceEight, 1, 8, 1, 1);
    sliderLayout->addWidget(transparenceOne, 1, 10, 1, 1);

    layout->addWidget(currentColorTextLabel);
    layout->addWidget(colorLabel);
    layout->addWidget(changeColorButton);
    layout->addWidget(lineThicknessTextLabel);
    layout->addWidget(lineThicknessValue);
    layout->addWidget(lineTransparencyTextLabel);
    layout->addLayout(sliderLayout);
    layout->addWidget(okButton);

    setLayout(layout);

    connect(changeColorButton, &QPushButton::clicked, this, &QLineParametersSelectionWindow::changeColor);
    connect(okButton, &QPushButton::clicked, this, &QLineParametersSelectionWindow::setLineParameters);
}

bool QLineParametersSelectionWindow::checkSubmitted() {
    return isSubmitted;
}

void QLineParametersSelectionWindow::changeColor() {
    color = QColorDialog::getColor(color, this );
    colorLabel->setStyleSheet("QLabel { background-color :"+color.name()+" }");
}

void QLineParametersSelectionWindow::setLineParameters() {
    isSubmitted = true;
    this->close();
}

QColor QLineParametersSelectionWindow::getColor() {
    return color;
}

int QLineParametersSelectionWindow::getLineThickness() {
    return lineThicknessValue->value();
}