#include "../../../include/qinterface/filtrationwindows/QMedianFiltrationWindow.h"

QMedianFiltrationWindow::QMedianFiltrationWindow() {
    isSubmitted = false;
    this->resize(200, 100);

    auto layout = new QVBoxLayout();
    auto medianLayout = new QHBoxLayout();
    auto medianLabel = new QLabel("Задайте радиус ядра ");
    radiusBox = new QSpinBox();
    radiusBox->setMinimum(1);
    radiusBox->setSingleStep(1);
    auto okButton = new QPushButton("Применить");

    medianLayout->addWidget(medianLabel);
    medianLayout->addWidget(radiusBox);

    layout->addItem(medianLayout);
    layout->addWidget(okButton);

    setLayout(layout);

    connect(okButton, &QPushButton::clicked, this, &QMedianFiltrationWindow::addFilter);
}

bool QMedianFiltrationWindow::checkSubmitted() {
    return isSubmitted;
}

void QMedianFiltrationWindow::addFilter() {
    isSubmitted = true;
    this->close();
}

int QMedianFiltrationWindow::getRadius() {
    return radiusBox->value();
}