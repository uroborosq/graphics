#include "QImageScalingWindow.h"
#include "QBCSplineWindow.h"

QImageScalingWindow::QImageScalingWindow() {
    isSubmitted = false;
    this->resize(200, 100);

    auto layout = new QVBoxLayout();
    auto scalingParametersLabel = new QLabel("Задайте параметры маштабирования");
    auto widthLayout = new QHBoxLayout();
    auto widhtLabel = new QLabel("Ширина: ");
    widhtBox = new QSpinBox();
    auto heightLayout = new QHBoxLayout();
    auto heightLabel = new QLabel("Высота: ");
    heightBox = new QSpinBox();
    auto shiftLabel = new QLabel("Смещение");
    auto xLayout = new QHBoxLayout();
    auto xLabel = new QLabel("X: ");
    xBox = new QSpinBox();
    auto yLayout = new QHBoxLayout();
    auto yLabel = new QLabel("Y: ");
    yBox = new QSpinBox();
    auto scalingLabel = new QLabel("Маштабирование");
    scalingComboBox = new QComboBox();
    auto okButton = new QPushButton("Применить");

    widhtBox->setMinimum(1);
    widhtBox->setValue(1);

    widthLayout->addWidget(widhtLabel);
    widthLayout->addWidget(widhtBox);

    heightBox->setMinimum(1);
    heightBox->setValue(1);

    heightLayout->addWidget(heightLabel);
    heightLayout->addWidget(heightBox);

    xBox->setMinimum(0);
    xBox->setValue(0);

    xLayout->addWidget(xLabel);
    xLayout->addWidget(xBox);

    yBox->setMinimum(0);
    yBox->setValue(0);

    yLayout->addWidget(yLabel);
    yLayout->addWidget(yBox);

    scalingComboBox->addItem("Ближайшая точка (метод ближайщего соседа)");
    scalingComboBox->addItem("Билинейное");
    scalingComboBox->addItem("Lanczos3");
    scalingComboBox->addItem("BC-сплайны");

    layout->addWidget(scalingParametersLabel);
    layout->addItem(widthLayout);
    layout->addItem(heightLayout);
    layout->addWidget(shiftLabel);
    layout->addItem(xLayout);
    layout->addItem(yLayout);
    layout->addWidget(scalingLabel);
    layout->addWidget(scalingComboBox);
    layout->addWidget(okButton);

    setLayout(layout);

    connect(okButton, &QPushButton::clicked, this, &QImageScalingWindow::scaleImage);
    connect(scalingComboBox, &QComboBox::activated,this, &QImageScalingWindow::bcSpline);
}

bool QImageScalingWindow::checkSubmitted() {
    return isSubmitted;
}

void QImageScalingWindow::scaleImage() {
    isSubmitted = true;
    this->close();
}

void QImageScalingWindow::bcSpline() {

    if (scalingComboBox->currentIndex() == 3) {
        auto bcSplineWindow = new QBCSplineWindow(bValue, cValue);
        bcSplineWindow->exec();

        if (bcSplineWindow->checkSubmitted()) {
            bValue = bcSplineWindow->getBValue();
            cValue = bcSplineWindow->getCValue();
        }
    }
}