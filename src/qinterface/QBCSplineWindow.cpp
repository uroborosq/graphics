#include "QBCSplineWindow.h"

QBCSplineWindow::QBCSplineWindow(double bValue, double cValue) {
    auto layout = new QVBoxLayout();
    auto bcSplineLabel = new QLabel("Задайте параметры");
    auto bSplineLyaout = new QHBoxLayout();
    auto bLabel = new QLabel("b: ");
    bBox = new QDoubleSpinBox();
    auto cSplineLyaout = new QHBoxLayout();
    auto cLabel = new QLabel("c: ");
    cBox = new QDoubleSpinBox();
    auto okButton = new QPushButton("Применить");

    bBox->setMinimum(0);
    bBox->setValue(bValue);
    bBox->setSingleStep(0.1);

    bSplineLyaout->addWidget(bLabel);
    bSplineLyaout->addWidget(bBox);

    cBox->setMinimum(0);
    cBox->setValue(cValue);
    cBox->setSingleStep(0.1);

    cSplineLyaout->addWidget(cLabel);
    cSplineLyaout->addWidget(cBox);

    layout->addWidget(bcSplineLabel);
    layout->addItem(bSplineLyaout);
    layout->addItem(cSplineLyaout);
    layout->addWidget(okButton);

    setLayout(layout);

    connect(okButton, &QPushButton::clicked, this, &QBCSplineWindow::changeParameters);
}

bool QBCSplineWindow::checkSubmitted() {
    return isSubmitted;
}

void QBCSplineWindow::changeParameters() {
    isSubmitted = true;
    this->close();
}

double QBCSplineWindow::getBValue() {
    return bBox->value();
}

double QBCSplineWindow::getCValue() {
    return cBox->value();
}