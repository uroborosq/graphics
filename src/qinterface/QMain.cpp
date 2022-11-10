#include "QMain.h"
#include "QImageWidget.h"
#include "QSavePictureWindow.h"
#include "Pnm.h"
#include "QOpenPictureWindow.h"

QMain::QMain(Pnm* file){

    this->resize(200, 300);
    auto layout = new QVBoxLayout();

    auto saveButton = new QPushButton("Сохранить как...");
    saveButton->setAutoDefault(true);

    auto picture = new QImageWidget(file->data, file->height, file->width, file->tag);

    auto fileMenu = new QMenu("Файл");

    auto openFile = new QAction("Открыть");
    openFile->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_O));
    connect(openFile, &QAction::triggered, [file, layout, picture, this](){
        auto openWindow = new QOpenPictureWindow(file, this);
        openWindow->show();
    });

    auto saveFile = new QAction("Сохранить как");
    saveFile->setShortcut(QKeySequence(Qt::CTRL + static_cast<Qt::Key>(Qt::SHIFT) + Qt::Key_S));
    connect(saveFile, &QAction::triggered, [&file](){
        auto saveWindow = new QSavePictureWindow(file);
        saveWindow->show();
    });

    auto colorspaceChange = new QAction("Изменить цветовое пространство");
    colorspaceChange->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_C));
    connect(colorspaceChange, &QAction::triggered, [&file](){
        auto changeColorspaceWindow = new QChangeColorspaceWindow();
        changeColorspaceWindow->show();
    });

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
        auto saveWindow = new QSavePictureWindow(file);
        saveWindow->show();
    });

}