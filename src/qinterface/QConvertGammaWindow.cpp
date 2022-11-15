#include "QConvertGammaWindow.h"

QConvertGammaWindow::QConvertGammaWindow() {
    this->resize(200, 100);

    auto sourceSpaceGroupBox = new QGroupBox("Source space");
    auto sourceSpaceLayout = new QHBoxLayout();
    auto profileLabel = new QLabel("Profile: ");
    auto sourceSpaceValue = new QLabel("sRGB IEC61966-2.1");
    sourceSpaceLayout->addWidget(profileLabel);
    sourceSpaceLayout->addWidget(sourceSpaceValue);
    sourceSpaceGroupBox->setLayout(sourceSpaceLayout);

    auto destinationSpaceGroupBox = new QGroupBox("Destination space");
    auto destinationSpaceLayout = new QHBoxLayout();
    auto destinationSpaceValue = new QComboBox();
    destinationSpaceValue->addItem("Working RGB - sRGB IEC61966-2.1");
    destinationSpaceLayout->addWidget(profileLabel);
    destinationSpaceLayout->addWidget(destinationSpaceValue);
    destinationSpaceGroupBox->setLayout(destinationSpaceLayout);

    auto okButton = new QPushButton("OK");

    auto grid = new QGridLayout();
    grid->addWidget(sourceSpaceGroupBox, 0, 0);
    grid->addWidget(destinationSpaceGroupBox, 1, 0);
    grid->addWidget(okButton, 2, 0);

    setLayout(grid);

    connect(okButton, &QPushButton::clicked, [=]() {
        this->close();
    });

}