#include "QAssignGammaWindow.h"

QAssignGammaWindow::QAssignGammaWindow() {
    isSubmitted = false;
    this->resize(200, 100);

    auto workingRGBButton = new QRadioButton("Интерпретировать как RGB: sRGB IEC61966-2.1");
    workingRGBButton->setChecked(true);

    profileButton = new QRadioButton("Другое значение: ");

    gammaBox = new QDoubleSpinBox();
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
        isSubmitted = true;
        this->close();
    });
}

bool QAssignGammaWindow::checkSubmited()
{
    return isSubmitted;
}

double QAssignGammaWindow::getNewGamma() {
    if (profileButton->isChecked()) {
        return gammaBox->value();
    }
    else{
        return sRGB;
    }
}