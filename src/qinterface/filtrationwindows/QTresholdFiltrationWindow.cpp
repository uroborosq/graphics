#include "QTresholdFiltrationWindow.h"

QTresholdFiltrationWindow::QTresholdFiltrationWindow() {
    isSubmitted = true;
    this->resize(200, 100);

    auto layout = new QVBoxLayout();
    auto filtrationRangeLabel = new QLabel("Задайте пороговый уровень");
    auto sliderLayout = new QGridLayout();
    thresholdFiltrationSlider = new QSlider(Qt::Horizontal);
    thresholdFiltrationValue = new QLabel("0");
    auto beginLabel = new QLabel("0");
    auto endLabel = new QLabel("255");
    auto okButton = new QPushButton("Применить");

    thresholdFiltrationSlider->setMinimum(0);
    thresholdFiltrationSlider->setMaximum(255);

    sliderLayout->addWidget(thresholdFiltrationSlider, 0, 0, 1, 1);
    sliderLayout->addWidget(thresholdFiltrationValue, 0, 1, 1, 1);
    sliderLayout->addWidget(beginLabel, 1, 0, 1, 1);
    sliderLayout->addWidget(endLabel, 1, 1, 1, 1);

    layout->addWidget(filtrationRangeLabel);
    layout->addItem(sliderLayout);
    layout->addWidget(okButton);
    setLayout(layout);

    connect(okButton, &QPushButton::clicked, this, &QTresholdFiltrationWindow::addFilter);
    connect(thresholdFiltrationSlider, &QSlider::valueChanged, this, &QTresholdFiltrationWindow::changeTresholdValue);
}

bool QTresholdFiltrationWindow::checkSubmitted() {
    return isSubmitted;
}

void QTresholdFiltrationWindow::addFilter() {
    isSubmitted = true;
    this->close();
}

void QTresholdFiltrationWindow::changeTresholdValue() {
    thresholdFiltrationValue->setText(" " + QString::number(thresholdFiltrationSlider->value()));
}

int QTresholdFiltrationWindow::getThresholdValue() {
    return thresholdFiltrationSlider->value();
}
