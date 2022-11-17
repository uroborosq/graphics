#include "QAssignGammaWindow.h"

QAssignGammaWindow::QAssignGammaWindow() {
    this->resize(200, 100);

    auto workingRGBButton = new QRadioButton("Интерпретировать как RGB: sRGB IEC61966-2.1");
    auto profileButton = new QRadioButton("Другое значение: ");

    workingRGBButton->setChecked(true);

    auto gammaBox = new QDoubleSpinBox();
    gammaBox->setValue(0);
    gammaBox->setMinimum(0);
    gammaBox->setSingleStep(0.2);

    auto profileLayout = new QHBoxLayout();
    profileLayout->addWidget(profileButton);
    profileLayout->addWidget(gammaBox);

    auto okButton = new QPushButton("OK");

    auto layout = new QVBoxLayout();
    layout->addWidget(workingRGBButton);
    layout->addItem(profileLayout);
    layout->addWidget(okButton);

    setLayout(layout);

    connect(okButton, &QPushButton::clicked, [=]() {
        this->close();
    });
}