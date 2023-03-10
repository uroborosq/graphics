#include "QMain.h"
#include "QImageWidget.h"
#include "QSavePictureWindow.h"
#include "QOpenPictureWindow.h"
#include "Pnm.h"
#include "QChangeColorspaceWindow.h"
#include "QAssignGammaWindow.h"
#include "QConvertGammaWindow.h"
#include "QLineParametersSelectionWindow.h"
#include "QDrawLineWindow.h"
#include "DrawColoredLine.h"
#include "QDitheringParametersWindow.h"
#include "QGradientGenerationWindow.h"
#include "QChooseImageDialog.h"
#include "FileOpenDecider.h"
#include "QImageScalingWindow.h"
#include "FiltrationEnum.h"
#include "QTresholdFiltrationWindow.h"
#include "QMedianFiltrationWindow.h"
#include "QGaussianFiltrationWindow.h"
#include "QLinearAveragingFiltrationWindow.h"
#include "QContrastAdaptiveSharpeningFiltrationWindow.h"

QMain::QMain(Pixels *pixels_, QImageWidget *picture_) {

    currentPixels = pixels_;
    picture = new QImageWidget(pixels_, this);
    this->resize(300, 300);

    auto fileMenu = new QMenu("Файл");

    auto chooseImage = new QAction("Выбрать изображение из открытых");
    fileMenu->addAction(chooseImage);
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

    auto drawLineMenu = new QMenu("Рисовать");

    auto drawLine = new QAction("Нарисовать линию");
    drawLine->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_D));

    auto lineParameters = new QAction("Изменить параметры линии");
    lineParameters->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_L));

    auto ditheringParameters = new QAction("Дизеринг");
    ditheringParameters->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_Z));

    auto gradientGeneration = new QAction("Сгенерировать изображение с горизонтальным градиентом");
    gradientGeneration->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_R));

    auto imageScaling = new QAction("Задать маштабирование");
    imageScaling->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_M));

    auto filtrationMenu = new QMenu("Применить фильтр к изображению");

    auto thresholdFilter = new QAction("Пороговая фильтрация");
    auto otsuThresholdFilter = new QAction("Пороговая фильтрация методом Оцу");
    auto medianFilter = new QAction("Медианный фильтр");
    auto gaussianFilter = new QAction("Фильтр Гаусса");
    auto linearAveragingFilter = new QAction("Линейный усредняющий фильтр (box blur)");
    auto sobelFilter = new QAction("Фильтр Собеля");
    auto contrastAdaptiveSharpeningFilter = new QAction("Contrast Adaptive Sharpening");
    auto noneFilter = new QAction("Без фильтрации");

    filtrationMenu->addAction(noneFilter);
    filtrationMenu->addAction(thresholdFilter);
    filtrationMenu->addAction(otsuThresholdFilter);
    filtrationMenu->addAction(medianFilter);
    filtrationMenu->addAction(gaussianFilter);
    filtrationMenu->addAction(linearAveragingFilter);
    filtrationMenu->addAction(sobelFilter);
    filtrationMenu->addAction(contrastAdaptiveSharpeningFilter);

    drawLineMenu->addAction(drawLine);
    drawLineMenu->addAction(lineParameters);

    fileMenu->addAction(openFile);
    fileMenu->addAction(saveFile);

    editMenu->addAction(colorspaceChange);
    editMenu->addAction(assignGamma);
    editMenu->addAction(convertGamma);
    editMenu->addMenu(drawLineMenu);
    editMenu->addAction(ditheringParameters);
    editMenu->addAction(gradientGeneration);
    editMenu->addMenu(filtrationMenu);
    editMenu->addAction(imageScaling);

    auto close = new QAction("Закрыть");
    close->setShortcut(QKeySequence(Qt::Key_Escape));
    connect(close, &QAction::triggered, [this]() {
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
    connect(drawLine, &QAction::triggered, this, &QMain::openDrawLineWindow);
    connect(lineParameters, &QAction::triggered, this, &QMain::openLineParametersWindow);
    connect(ditheringParameters, &QAction::triggered, this, &QMain::openDitheringParametersWindow);
    connect(gradientGeneration, &QAction::triggered, this, &QMain::openGradientGenerationWindow);
    connect(chooseImage, &QAction::triggered, this, &QMain::openImageChooseDialog);
    connect(thresholdFilter, &QAction::triggered, this, &QMain::openTresholdFiltrationWindow);
    connect(otsuThresholdFilter, &QAction::triggered, this, &QMain::openOtsuThresholdFiltrationWindow);
    connect(medianFilter, &QAction::triggered, this, &QMain::openMedianFiltrationWindow);
    connect(gaussianFilter, &QAction::triggered, this, &QMain::openGaussianFiltrationWindow);
    connect(linearAveragingFilter, &QAction::triggered, this, &QMain::openLinearAveragingFiltrationWindow);
    connect(sobelFilter, &QAction::triggered, this, &QMain::openSobelFiltrationWindow);
    connect(contrastAdaptiveSharpeningFilter, &QAction::triggered, this,
            &QMain::openContrastAdaptiveSharpeningFiltrationWindow);
    connect(noneFilter, &QAction::triggered, this, &QMain::removeFiltering);
    connect(imageScaling, &QAction::triggered, this, &QMain::openImageScalingWindow);
}

void QMain::openOpenWindow() {
    auto openWindow = new QOpenPictureWindow();
    openWindow->exec();
    try {
        if (openWindow->checkSubmitted()) {
            auto path = openWindow->getPicturePath();
            auto colorspaceChoice = openWindow->getColorSpace();
            AbstractFile* file = getFileOpener(path);

            if (file == nullptr)
                throw std::invalid_argument("Unknown error");

            auto data  = file->read(path);
            auto info = file->getImageInfo();
            auto tmp = new Pixels(data, info.width, info.height, info.fileFormat, info.channels, colorspaceChoice, ColorChannel::All, 0);
            currentPixels = tmp;

            delete picture;
            picture = new QImageWidget(currentPixels, this);
            this->setCentralWidget(picture);
            images[path] = tmp;
        }
    }
    catch (const std::invalid_argument &e) {
        auto messageBox = new QMessageBox();
        messageBox->setText(e.what());
        messageBox->exec();
    }
}

void QMain::openSaveWindow() {
    auto saveWindow = new QSavePictureWindow();
    saveWindow->exec();
    try {
        if (saveWindow->checkSubmitted()) {
            auto savePicturePath = saveWindow->getPicturePath();
            auto fileFormat = saveWindow->getFormat();
            auto file = getFileOpener(fileFormat);
            FileImageInfo info{};
            info.width = currentPixels->getWidth();
            info.height = currentPixels->getHeight();
            info.depth = 8;
            info.channels = currentPixels->getNumberOfChannels();
            info.fileFormat = currentPixels->getTag();
            auto tmp = currentPixels->getGamma();
            currentPixels->setGamma(0);
            auto data = remove_other_channels(currentPixels->getValues(), currentPixels->getColorChannel());
            file->write(savePicturePath, data, info);
            currentPixels->setGamma(tmp);
        }
    }
    catch (const std::invalid_argument &e) {
        auto box = new QMessageBox();
        box->setText(e.what());
        box->exec();
    }
}

void QMain::openColorSpaceAndChannelWindow() {
    auto changeColorspaceWindow = new QChangeColorspaceWindow(currentPixels->getColorSpace(),
                                                              currentPixels->getColorChannel());
    changeColorspaceWindow->exec();

    auto colorSpace = changeColorspaceWindow->getColorSpace();
    auto colorChannel = changeColorspaceWindow->getColorChannel();

    delete picture;

    currentPixels->setColorSpace(colorSpace);
    currentPixels->setColorChannel(colorChannel);

    picture = new QImageWidget(currentPixels, this);
    this->setCentralWidget(picture);
}

void QMain::openAssignGammaWindow() {
    auto assignGammaWindow = new QAssignGammaWindow(picture->getGamma());
    assignGammaWindow->exec();
    if (assignGammaWindow->checkSubmited()) {
        picture->setGamma(assignGammaWindow->getNewGamma());
        this->setCentralWidget(picture);
    }
}

void QMain::openConvertGammaWindow() {
    auto convertGammaWindow = new QConvertGammaWindow(currentPixels->getGamma());
    convertGammaWindow->exec();
    if (convertGammaWindow->checkSubmited()) {
        auto gamma = picture->getGamma();
        delete picture;
        currentPixels->setGamma(convertGammaWindow->getNewGamma());
        picture = new QImageWidget(currentPixels, this);
        picture->setGamma(gamma);
        this->setCentralWidget(picture);
    }
}

void QMain::openDrawLineWindow() {
    auto drawLineWindow = new QDrawLineWindow(currentPixels, &picture, this, lineColor, lineThickness,
                                              lineTransparency);
    drawLineWindow->show();
}

void QMain::openLineParametersWindow() {
    auto lineParametersWindow = new QLineParametersSelectionWindow();
    lineParametersWindow->exec();
    if (lineParametersWindow->checkSubmitted()) {
        lineColor = lineParametersWindow->getColor();
        lineThickness = lineParametersWindow->getLineThickness();
        lineTransparency = lineParametersWindow->getLineTransparency();
    }
}

void QMain::openDitheringParametersWindow() {
    auto ditheringParametersWindow = new QDitheringParametersWindow(currentPixels, this);
    ditheringParametersWindow->exec();
    delete picture;
    picture = new QImageWidget(currentPixels, this);
    setCentralWidget(picture);
}

void QMain::openGradientGenerationWindow() {
    auto gradientGenerationWindow = new QGradientGenerationWindow(currentPixels->getWidth(),
                                                                  currentPixels->getHeight());
    gradientGenerationWindow->exec();
    auto newPixels = gradientGenerationWindow->getGradient();
    if (newPixels != nullptr) {
        delete picture;
        picture = new QImageWidget(newPixels, this);
        currentPixels = newPixels;
        images["Gradient" + std::to_string(gradientCounter)] = newPixels;
        gradientCounter++;
        setCentralWidget(picture);
    }
}

void QMain::openImageChooseDialog() {
    auto names = std::vector<std::string>();

    for (auto &image: images) {
        names.push_back(image.first);
    }

    auto dialog = QChooseImageDialog(names);
    dialog.exec();

    if (dialog.checkSubmitted())
    {
        auto choose = dialog.getChosenImage();
        currentPixels = images[choose];
        delete picture;
        picture = new QImageWidget(currentPixels, this);
        setCentralWidget(picture);
    }

}

void QMain::openTresholdFiltrationWindow() {
    auto tresholdFiltrationWindow = new QTresholdFiltrationWindow();
    tresholdFiltrationWindow->exec();

    if (tresholdFiltrationWindow->checkSubmitted()) {
        FilterConfiguration config{};
        auto filter = Filtration::Threshold;
        config.threshold = (float)tresholdFiltrationWindow->getThresholdValue();
        currentPixels->setFiltering(filter, config);
        updatePicture();
    }
}

void QMain::openOtsuThresholdFiltrationWindow() {
    auto filter = Filtration::OtsuThreshold;
    currentPixels->setFiltering(filter, FilterConfiguration{});
    updatePicture();
}

void QMain::openMedianFiltrationWindow() {
    auto medianFiltrationWindow = new QMedianFiltrationWindow();
    medianFiltrationWindow->exec();

    if (medianFiltrationWindow->checkSubmitted()) {
        FilterConfiguration config{};
        auto filter = Filtration::Median;
        config.radius = medianFiltrationWindow->getRadius();
        currentPixels->setFiltering(filter, config);
        updatePicture();
    }
}

void QMain::openGaussianFiltrationWindow() {
    auto gaussianFiltrationWindow = new QGaussianFiltrationWindow();
    gaussianFiltrationWindow->exec();

    if (gaussianFiltrationWindow->checkSubmitted()) {
        FilterConfiguration config{};
        auto filter = Filtration::Gaussian;
        config.sigma = gaussianFiltrationWindow->getSigma();
        currentPixels->setFiltering(filter, config);
        updatePicture();
    }
}

void QMain::openLinearAveragingFiltrationWindow() {
    auto linearAveragingFiltrationWindow = new QLinearAveragingFiltrationWindow();
    linearAveragingFiltrationWindow->exec();

    if (linearAveragingFiltrationWindow->checkSubmitted()) {
        FilterConfiguration config{};
        auto filter = Filtration::LinearAveraging;
        config.radius = linearAveragingFiltrationWindow->getRadius();
        currentPixels->setFiltering(filter, config);
        updatePicture();
    }



}

void QMain::openSobelFiltrationWindow() {
    auto filter = Filtration::Sobel;
    currentPixels->setFiltering(filter, FilterConfiguration{});
    updatePicture();
}

void QMain::openContrastAdaptiveSharpeningFiltrationWindow() {
    auto contrastAdaptiveSharpeningFiltrationWindow = new QContrastAdaptiveSharpeningFiltrationWindow();
    contrastAdaptiveSharpeningFiltrationWindow->exec();

    if (contrastAdaptiveSharpeningFiltrationWindow->checkSubmitted()) {
        FilterConfiguration config{};
        auto filter = Filtration::ContrastAdaptiveSharpening;
        config.sharpness = (float)contrastAdaptiveSharpeningFiltrationWindow->getSharpness() / 255.0f;
        currentPixels->setFiltering(filter, config);
        updatePicture();
    }
}

void QMain::updatePicture() {
    delete picture;
    picture = new QImageWidget(currentPixels, this);
    setCentralWidget(picture);
}

void QMain::removeFiltering() {
    currentPixels->setFiltering(NoFiltration, FilterConfiguration{});
    updatePicture();
}

void QMain::openImageScalingWindow() {
    auto imageScalingWindow = new QImageScalingWindow();
    imageScalingWindow->exec();
    if (imageScalingWindow->checkSubmitted()) {
        auto interpolation = imageScalingWindow->getInterpolationParameters();
        auto newWidth = imageScalingWindow->getWidth();
        auto newHeight = imageScalingWindow->getHeight();
        auto x = imageScalingWindow->getXShift();
        auto y = imageScalingWindow->getYShift();
        auto b = imageScalingWindow->getBValue();
        auto c = imageScalingWindow->getCValue();
        currentPixels->setInterpolation(interpolation, newWidth, newHeight, x, y, b, c);
        delete picture;
        picture = new QImageWidget(currentPixels, this);
        setCentralWidget(picture);
    }
}