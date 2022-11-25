#include <QSpinBox>
#include "QDrawLineWindow.h"
#include "DrawColoredLine.h"

QDrawLineWindow::QDrawLineWindow(Pixels* pixels, QImageWidget** picture, QMain* mainWindow, QColor color, int lineThickness, float lineTransparency) {
    this->resize(200, 100);

    _pixels = pixels;
    _picture = picture;
    _mainWindow = mainWindow;
    _color = color;
    _lineThickness = lineThickness;
    _lineTransparency = lineTransparency;

    auto choosePointsLabel = new QLabel("Выберите точки начала и конца линии:");
    auto firstPointLabel = new QLabel("Первая точка: ");
    auto firstPointXLabel = new QLabel("x: ");
    auto firstPointYLabel = new QLabel(" y: ");
    firstPointXValue = new QLabel("0");
    firstPointYValue = new QLabel("0");
    auto firstPointChooseButton = new QPushButton("Выбрать точку");
    auto secondPointLabel = new QLabel("Вторая точка: ");
    auto secondPointXLabel = new QLabel("x: ");
    auto secondPointYLabel = new QLabel(" y: ");
    secondPointXValue = new QLabel("0");
    secondPointYValue = new QLabel("0");
    auto secondPointChooseButton = new QPushButton("Выбрать точку");
    auto drawButton = new QPushButton("Нарисовать линию");

    auto layout = new QVBoxLayout();
    auto firstPointLayout = new QHBoxLayout();
    auto secondPointLayout = new QHBoxLayout();
    auto grayLabel = new QLabel("Цвет для серой картинки");
    graySpin = new QSpinBox();
    graySpin->setMaximum(255);
    graySpin->setMinimum(0);
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
    layout->addWidget(grayLabel);
    layout->addWidget(graySpin);
    layout->addWidget(drawButton);

    setLayout(layout);

    connect(firstPointChooseButton, &QPushButton::clicked, this, &QDrawLineWindow::chooseFirstPoint);
    connect(secondPointChooseButton, &QPushButton::clicked, this, &QDrawLineWindow::chooseSecondPoint);
    connect(drawButton, &QPushButton::clicked, this, &QDrawLineWindow::draw);
}

void QDrawLineWindow::chooseFirstPoint() {
    auto x = (*_picture)->getMousePressXCoordinate();
    auto y = (*_picture)->getMousePressYCoordinate();
    firstPointXValue->setText(QString::number(x));
    firstPointYValue->setText(QString::number(y));
}

void QDrawLineWindow::chooseSecondPoint() {
    secondPointXValue->setText(QString::number((*_picture)->getMousePressXCoordinate()));
    secondPointYValue->setText(QString::number((*_picture)->getMousePressYCoordinate()));
}

void QDrawLineWindow::draw()
{
    auto drawer = new DrawColoredLine();
    auto x0 = firstPointXValue->text().toLongLong();
    auto y0 = firstPointYValue->text().toLongLong();
    auto x1 = secondPointXValue->text().toLongLong();
    auto y1 = secondPointYValue->text().toLongLong();
    std::vector<float> color;
    if (_pixels->getTag() == PnmFormat::P6)
    color = std::vector<float>{static_cast<float>(_color.red()), static_cast<float>(_color.green()), static_cast<float>(_color.blue())};
    else if (_pixels->getTag() == PnmFormat::P5)
        color = std::vector<float>{static_cast<float>(graySpin->value())};

    _pixels->drawLine(drawer, x0, y0, x1, y1, color, _lineThickness, 1 - _lineTransparency);
    delete *_picture;
    *_picture = new QImageWidget(_pixels, _mainWindow);
    _mainWindow->setCentralWidget(*_picture);

    this->close();
}
