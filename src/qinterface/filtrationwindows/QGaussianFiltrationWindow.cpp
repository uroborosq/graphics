#include "QGaussianFiltrationWindow.h"

QGaussianFiltrationWindow::QGaussianFiltrationWindow() {
    isSubmitted = false;
    this->resize(200, 100);

    auto layout = new QVBoxLayout();
    auto sigmaLayout = new QHBoxLayout();
    auto sigmaLabel = new QLabel("Задайте сигму");
    sigmaBox = new QLineEdit("0.5");
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

float QGaussianFiltrationWindow::getSigma() {
    return std::stof(sigmaBox->text().toStdString());
}