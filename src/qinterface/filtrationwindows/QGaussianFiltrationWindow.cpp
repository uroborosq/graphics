#include "../../../include/qinterface/filtrationwindows/QGaussianFiltrationWindow.h"

QGaussianFiltrationWindow::QGaussianFiltrationWindow() {
    isSubmitted = false;
    this->resize(200, 100);

    auto layout = new QVBoxLayout();
    auto sigmaLayout = new QHBoxLayout();
    auto sigmaLabel = new QLabel("Задайте сигму");
    sigmaBox = new QSpinBox();
    sigmaBox->setMinimum(1);
    sigmaBox->setSingleStep(1);
    auto okButton = new QPushButton("Применить");

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

int QGaussianFiltrationWindow::getSigma() {
    return sigmaBox->value();
}