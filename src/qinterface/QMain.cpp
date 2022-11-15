#include "QMain.h"
#include "QImageWidget.h"
#include "QSavePictureWindow.h"
#include "QOpenPictureWindow.h"
#include "Pnm.h"
#include "QChangeColorspaceWindow.h"

void QMain::openOpenWindow() {
    auto openWindow = new QOpenPictureWindow(pixels, this);
    openWindow->show();
}

void QMain::openColorSpaceAndChannelWindow() {
    auto changeColorspaceWindow = new QChangeColorspaceWindow(pixels, this);
    changeColorspaceWindow->show();
}


QMain::QMain(Pixels* pixels_){
    pixels = pixels_;
    this->resize(200, 300);
    auto layout = new QVBoxLayout();

    auto saveButton = new QPushButton("Сохранить как...");
    saveButton->setAutoDefault(true);

    auto picture = new QImageWidget(pixels);

    auto fileMenu = new QMenu("Файл");

    auto openFile = new QAction("Открыть");
    openFile->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_O));

    auto saveFile = new QAction("Сохранить как");
    saveFile->setShortcut(QKeySequence(Qt::CTRL | static_cast<Qt::Key>(Qt::SHIFT) + Qt::Key_S));
    connect(saveFile, &QAction::triggered, this, [this](){
        auto saveWindow = new QSavePictureWindow(pixels);
        saveWindow->show();
    });

    auto colorspaceChange = new QAction("Изменить цветовое пространство");
    colorspaceChange->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_C));

    fileMenu->addAction(openFile);
    fileMenu->addAction(saveFile);
    fileMenu->addAction(colorspaceChange);

    auto close = new QAction("Закрыть");
    close->setShortcut(QKeySequence(Qt::Key_Escape));
    connect(close, &QAction::triggered, [this](){
        this->close();
    });

    auto menuBar = new QMenuBar();
    menuBar->addMenu(fileMenu);
    menuBar->addAction(close);

    this->setMenuBar(menuBar);
    this->setCentralWidget(picture);

    connect(saveButton, &QPushButton::clicked, this, [=]() {
        auto saveWindow = new QSavePictureWindow(pixels);
        saveWindow->show();
    });
    connect(colorspaceChange, &QAction::triggered, this, &QMain::openColorSpaceAndChannelWindow);
    connect(openFile, &QAction::triggered, this, &QMain::openOpenWindow);

}


