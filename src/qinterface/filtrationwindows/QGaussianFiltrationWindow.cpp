#include "QGaussianFiltrationWindow.h"

QGaussianFiltrationWindow::QGaussianFiltrationWindow() {
    isSubmitted = false;
    this->resize(200, 100);

    auto layout = new QVBoxLayout();
    auto sigmaLayout = new QHBoxLayout();
    auto sigmaLabel = new QLabel("Задайте сигму");
    auto okButton = new QPushButton("Применить");
    sigmaBox = new QDoubleSpinBox();
    sigmaBox->setValue(0.5);
    sigmaBox->setMinimum(0);
    sigmaBox->setSingleStep(0.1);
    sigmaLayout->addWidget(sigmaLabel);
    sigmaLayout->addWidget(sigmaBox);

    layout->addItem(sigmaLayout);
    layout->addWidget(okButton);

    setLayout(layout);

    connect(okButton, &QPushButton::clicked, this, &QGaussianFiltrationWindow::addFilter);
}

bool QGaussianFiltrationWindow::checkSubmitted() {
    return isSubmitted;
}

void QGaussianFiltrationWindow::addFilter() {
    isSubmitted = true;
    this->close();
}

float QGaussianFiltrationWindow::getSigma() {
    return (float)sigmaBox->value();
}