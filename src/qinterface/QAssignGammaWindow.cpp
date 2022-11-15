#include "QAssignGammaWindow.h"

QAssignGammaWindow::QAssignGammaWindow() {
    this->resize(200, 100);

    auto workingRGBButton = new QRadioButton("Working RGB:  sRGB IEC61966-2.1");
    auto profileButton = new QRadioButton("Profile: ");


    auto gammaBox = new QComboBox();
    gammaBox->addItem("Adobe RGB(1998)");

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