#include "QLinearAveragingFiltrationWindow.h"

QLinearAveragingFiltrationWindow::QLinearAveragingFiltrationWindow() {
    isSubmitted = false;
    this->resize(200, 100);

    auto layout = new QVBoxLayout();
    auto linearAveragingLayout = new QHBoxLayout();
    auto linearAveragingLabel = new QLabel("Задайте радиус ядра ");
    radiusBox = new QSpinBox();
    radiusBox->setMinimum(1);
    radiusBox->setSingleStep(1);
    auto okButton = new QPushButton("Применить");

    linearAveragingLayout->addWidget(linearAveragingLabel);
    linearAveragingLayout->addWidget(radiusBox);

    layout->addItem(linearAveragingLayout);
    layout->addWidget(okButton);

    setLayout(layout);

    connect(okButton, &QPushButton::clicked, this, &QLinearAveragingFiltrationWindow::addFilter);
}

bool QLinearAveragingFiltrationWindow::checkSubmitted() {
    return isSubmitted;
}

void QLinearAveragingFiltrationWindow::addFilter() {
    isSubmitted = true;
    this->close();
}

int QLinearAveragingFiltrationWindow::getRadius() {
    return radiusBox->value();
}

