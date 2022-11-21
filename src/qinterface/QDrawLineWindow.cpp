#include "QDrawLineWindow.h"

QDrawLineWindow::QDrawLineWindow(QImageWidget* picture) {
    this->resize(200, 100);

    _picture = picture;

    auto choosePointsLabel = new QLabel("Выберите точки начала и конца линии:");
    auto firstPointLabel = new QLabel("Первая точка: ");
    auto firstPointXLabel = new QLabel("x: ");
    auto firstPointYLabel = new QLabel(" y: ");
    firstPointXValue = new QLabel();
    firstPointYValue = new QLabel();
    auto firstPointChooseButton = new QPushButton("Выбрать точку");
    auto secondPointLabel = new QLabel("Вторая точка: ");
    auto secondPointXLabel = new QLabel("x: ");
    auto secondPointYLabel = new QLabel(" y: ");
    secondPointXValue = new QLabel();
    secondPointYValue = new QLabel();
    auto secondPointChooseButton = new QPushButton("Выбрать точку");
    auto drawButton = new QPushButton("Нарисовать линию");

    auto layout = new QVBoxLayout();
    auto firstPointLayout = new QHBoxLayout();
    auto secondPointLayout = new QHBoxLayout();

    firstPointLayout->addWidget(firstPointLabel);
    firstPointLayout->addWidget(firstPointXLabel);
    firstPointLayout->addWidget(firstPointXValue);
    firstPointLayout->addWidget(firstPointYLabel);
    firstPointLayout->addWidget(firstPointYValue);

    secondPointLayout->addWidget(secondPointLabel);
    secondPointLayout->addWidget(secondPointXLabel);
    secondPointLayout->addWidget(secondPointXValue);
    secondPointLayout->addWidget(secondPointYLabel);
    secondPointLayout->addWidget(secondPointYValue);

    layout->addWidget(choosePointsLabel);
    layout->addLayout(firstPointLayout);
    layout->addWidget(firstPointChooseButton);
    layout->addLayout(secondPointLayout);
    layout->addWidget(secondPointChooseButton);
    layout->addWidget(drawButton);

    setLayout(layout);

    connect(firstPointChooseButton, &QPushButton::clicked, this, &QDrawLineWindow::chooseFirstPoint);
    connect(secondPointChooseButton, &QPushButton::clicked, this, &QDrawLineWindow::chooseSecondPoint);
    connect(drawButton, &QPushButton::clicked, this, &QDrawLineWindow::drawLine);
}

void QDrawLineWindow::chooseFirstPoint() {
    firstPointXValue->setText(QString::number(_picture->getMousePressXCoordinate()));
    firstPointYValue->setText(QString::number(_picture->getMousePressYCoordinate()));
}

void QDrawLineWindow::chooseSecondPoint() {
    secondPointXValue->setText(QString::number(_picture->getMousePressXCoordinate()));
    secondPointYValue->setText(QString::number(_picture->getMousePressYCoordinate()));
}

void QDrawLineWindow::drawLine() {
    this->close();
}