#include "QConvertGammaWindow.h"

QConvertGammaWindow::QConvertGammaWindow(double gamma) {
    isSubmitted = false;
    sourseSpaceValue = gamma;
    this->resize(200, 100);

    auto grid = new QGridLayout();
    auto sourceSpaceGroupBox = new QGroupBox("Текущее значение гаммы");
    auto sourceSpaceLayout = new QHBoxLayout();
    auto sourceProfileLabel = new QLabel("Значение: ");

    sourceSpaceLabel = new QLabel();
    sourceSpaceLabel->setText(QString::number(sourseSpaceValue));
    sourceSpaceLayout->addWidget(sourceProfileLabel);
    sourceSpaceLayout->addWidget(sourceSpaceLabel);
    sourceSpaceGroupBox->setLayout(sourceSpaceLayout);
    grid->addWidget(sourceSpaceGroupBox, 0, 0);

    auto destinationSpaceGroupBox = new QGroupBox("Задать гамму");
    auto destinationSpaceLayout = new QHBoxLayout();
    auto destinationProfileLabel = new QLabel("Значение: ");
    destinationSpaceSpinBox = new QDoubleSpinBox();
    destinationSpaceSpinBox->setValue(0);
    destinationSpaceSpinBox->setMinimum(0);
    destinationSpaceSpinBox->setSingleStep(0.2);
    destinationSpaceLayout->addWidget(destinationProfileLabel);
    destinationSpaceLayout->addWidget(destinationSpaceSpinBox);
    destinationSpaceGroupBox->setLayout(destinationSpaceLayout);
    grid->addWidget(destinationSpaceGroupBox, 1, 0);

    auto okButton = new QPushButton("OK");
    grid->addWidget(okButton, 2, 0);

    setLayout(grid);

    connect(okButton, &QPushButton::clicked, this, &QConvertGammaWindow::changeGammaValue);
}

void QConvertGammaWindow::changeGammaValue() {
    isSubmitted = true;
    this->close();
}

bool QConvertGammaWindow::checkSubmited()
{
    return isSubmitted;
}

double QConvertGammaWindow::getNewGamma() {
    return destinationSpaceSpinBox->value();
}
