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
    auto lineTransparencyTextLabel = new QLabel("Прозрачность линии (%):");
    auto sliderLayout = new QGridLayout();
    lineTransparencyValue = new QSlider(Qt::Horizontal);
    auto transparenceZero = new QLabel("0");
    auto transparenceOne = new QLabel("100");
    showTransparencyValueLabel = new QLabel("100%");
    auto okButton = new QPushButton("OK");

    colorLabel->setStyleSheet("QLabel { background-color :"+color.name()+" }");

    lineThicknessValue->setValue(1);
    lineThicknessValue->setMinimum(1);

    lineTransparencyValue->setRange(0, 100);
    lineTransparencyValue->setValue(100);
    lineTransparencyValue->setPageStep(1);

    sliderLayout->addWidget(lineTransparencyValue, 0, 0, 1, 1);
    sliderLayout->addWidget(showTransparencyValueLabel, 0, 1, 1, 1);
    sliderLayout->addWidget(transparenceZero, 1, 0, 1, 1);
    sliderLayout->addWidget(transparenceOne, 1, 1, 1, 1);

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
    connect(lineTransparencyValue, &QSlider::valueChanged, this, &QLineParametersSelectionWindow::showTransparencyValue);
}

bool QLineParametersSelectionWindow::checkSubmitted() {
    return isSubmitted;
}

void QLineParametersSelectionWindow::changeColor() {
    color = QColorDialog::getColor(color, this );
    colorLabel->setStyleSheet("QLabel { background-color :"+color.name()+" }");
}

void QLineParametersSelectionWindow::showTransparencyValue() {
    showTransparencyValueLabel->setText(QString::number(lineTransparencyValue->value()) + "%");
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

float QLineParametersSelectionWindow::getLineTransparency() {
    return (float)lineTransparencyValue->value()/100;
}