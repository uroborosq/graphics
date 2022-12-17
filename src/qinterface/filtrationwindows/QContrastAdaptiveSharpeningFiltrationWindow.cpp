#include "QContrastAdaptiveSharpeningFiltrationWindow.h"

QContrastAdaptiveSharpeningFiltrationWindow::QContrastAdaptiveSharpeningFiltrationWindow() {
    isSubmitted = true;
    this->resize(200, 100);

    auto layout = new QVBoxLayout();
    auto filtrationRangeLabel = new QLabel("Задайте пороговый уровень");
    auto sliderLayout = new QGridLayout();
    sharpnessSlider = new QSlider(Qt::Horizontal);
    sharpnessValue = new QLabel("0");
    auto beginLabel = new QLabel("0");
    auto endLabel = new QLabel("255");
    auto okButton = new QPushButton("Применить");

    sharpnessSlider->setMinimum(0);
    sharpnessSlider->setMaximum(255);

    sliderLayout->addWidget(sharpnessSlider, 0, 0, 1, 1);
    sliderLayout->addWidget(sharpnessValue, 0, 1, 1, 1);
    sliderLayout->addWidget(beginLabel, 1, 0, 1, 1);
    sliderLayout->addWidget(endLabel, 1, 1, 1, 1);

    layout->addWidget(filtrationRangeLabel);
    layout->addItem(sliderLayout);
    layout->addWidget(okButton);
    setLayout(layout);

    connect(okButton, &QPushButton::clicked, this, &QContrastAdaptiveSharpeningFiltrationWindow::addFilter);
    connect(sharpnessSlider, &QSlider::valueChanged, this, &QContrastAdaptiveSharpeningFiltrationWindow::changeSharpnessValue);
}

bool QContrastAdaptiveSharpeningFiltrationWindow::checkSubmitted() {
    return isSubmitted;
}

void QContrastAdaptiveSharpeningFiltrationWindow::addFilter() {
    isSubmitted = true;
    this->close();
}

void QContrastAdaptiveSharpeningFiltrationWindow::changeSharpnessValue() {
    sharpnessValue->setText(" " + QString::number(sharpnessSlider->value()));
}

int QContrastAdaptiveSharpeningFiltrationWindow::getSharpness() {
    return sharpnessSlider->value();
}