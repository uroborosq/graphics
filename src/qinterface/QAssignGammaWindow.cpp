#include "QAssignGammaWindow.h"

QAssignGammaWindow::QAssignGammaWindow(const float &currentGamma) {
    isSubmitted = false;
    this->resize(200, 100);

    auto workingRGBButton = new QRadioButton("sRGB");
    profileButton = new QRadioButton("Другое значение: ");

    gammaBox = new QDoubleSpinBox();
    gammaBox->setMinimum(0);
    gammaBox->setSingleStep(0.1);

    if (currentGamma == 0) {
        workingRGBButton->setChecked(true);
        gammaBox->setValue(0);
    } else {
        gammaBox->setValue(currentGamma);
        profileButton->setChecked(true);
    }

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

bool QAssignGammaWindow::checkSubmited() {
    return isSubmitted;
}

double QAssignGammaWindow::getNewGamma() {
    if (profileButton->isChecked()) {
        return gammaBox->value();
    } else {
        return sRGB;
    }
}