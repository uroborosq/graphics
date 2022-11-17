#include "QConvertGammaWindow.h"

QConvertGammaWindow::QConvertGammaWindow() {
    this->resize(200, 100);

    auto grid = new QGridLayout();

    auto sourceSpaceGroupBox = new QGroupBox("Текущее значение гаммы");
    auto sourceSpaceLayout = new QHBoxLayout();
    auto sourceProfileLabel = new QLabel("Значение: ");
    sourceSpaceLabel = new QLabel();
    sourceSpaceLabel->setText("2.2");
    sourceSpaceLayout->addWidget(sourceProfileLabel);
    sourceSpaceLayout->addWidget(this->sourceSpaceLabel);
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
    sourceSpaceLabel->setText(QString::number(destinationSpaceSpinBox->value()));
    this->close();
}