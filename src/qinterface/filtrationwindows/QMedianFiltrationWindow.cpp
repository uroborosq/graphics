#include "../../../include/qinterface/filtrationwindows/QMedianFiltrationWindow.h"

QMedianFiltrationWindow::QMedianFiltrationWindow() {
    isSubmitted = false;
    this->resize(200, 100);

    auto layout = new QHBoxLayout();
    auto medianLabel = new QLabel("Задайте радиус ядра");
    medianBox = new QSpinBox();
    medianBox->setMinimum(1);
    medianBox->setSingleStep(1);
    auto okButton = new QPushButton("Применить");

    layout->addWidget(medianLabel);
    layout->addWidget(medianBox);
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
    return medianBox->value();
}