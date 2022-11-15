#include "QMain.h"
#include "QImageWidget.h"
#include "QSavePictureWindow.h"
#include "QOpenPictureWindow.h"
#include "Pnm.h"
#include "QChangeColorspaceWindow.h"
#include "QAssignGammaWindow.h"
#include "QConvertGammaWindow.h"

void QMain::openOpenWindow() {
    auto openWindow = new QOpenPictureWindow(pixels, this);
    openWindow->show();
}

void QMain::openSaveWindow() {
    auto saveWindow = new QSavePictureWindow(pixels);
    saveWindow->show();
}

void QMain::openColorSpaceAndChannelWindow() {
    auto changeColorspaceWindow = new QChangeColorspaceWindow(pixels, this);
    changeColorspaceWindow->show();
}

void QMain::openAssignGammaWindow() {
    auto assignGammaWindow = new QAssignGammaWindow();
    assignGammaWindow->show();
}

void QMain::openConvertGammaWindow() {
    auto convertGammaWindow = new QConvertGammaWindow();
    convertGammaWindow->show();
}


QMain::QMain(Pixels* pixels_){
    pixels = pixels_;
    this->resize(200, 300);

    auto picture = new QImageWidget(pixels);

    auto fileMenu = new QMenu("Файл");

    auto openFile = new QAction("Открыть");
    openFile->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_O));

    auto saveFile = new QAction("Сохранить как");
    saveFile->setShortcut(QKeySequence(Qt::CTRL | static_cast<Qt::Key>(Qt::SHIFT) + Qt::Key_S));

    auto editMenu = new QMenu("Редактировать");

    auto colorspaceChange = new QAction("Изменить цветовое пространство");
    colorspaceChange->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_C));

    auto assignGamma = new QAction("Назначить гамму");
    assignGamma->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_A));

    auto convertGamma = new QAction("Преобразовать гамму");
    convertGamma->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_G));

    fileMenu->addAction(openFile);
    fileMenu->addAction(saveFile);

    editMenu->addAction(colorspaceChange);
    editMenu->addAction(assignGamma);
    editMenu->addAction(convertGamma);

    auto close = new QAction("Закрыть");
    close->setShortcut(QKeySequence(Qt::Key_Escape));
    connect(close, &QAction::triggered, [this](){
        this->close();
    });

    auto menuBar = new QMenuBar();
    menuBar->addMenu(fileMenu);
    menuBar->addMenu(editMenu);
    menuBar->addAction(close);

    this->setMenuBar(menuBar);
    this->setCentralWidget(picture);

    connect(openFile, &QAction::triggered, this, &QMain::openOpenWindow);
    connect(saveFile, &QAction::triggered, this, &QMain::openSaveWindow);
    connect(colorspaceChange, &QAction::triggered, this, &QMain::openColorSpaceAndChannelWindow);
    connect(assignGamma, &QAction::triggered, this, &QMain::openAssignGammaWindow);
    connect(convertGamma, &QAction::triggered, this, &QMain::openConvertGammaWindow);

}


