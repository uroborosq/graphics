#ifndef HOROSHOEDITOR_QOPENPICTUREWINDOW_H
#define HOROSHOEDITOR_QOPENPICTUREWINDOW_H

#include <QWidget>
#include <QApplication>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <QComboBox>
#include "Pnm.h"
#include "QMain.h"


class QOpenPictureWindow : public QWidget {
private:
    Pixels* pixels;
    QMain* mainWindow;
    QLineEdit* picturePath;
    QComboBox* colorspaces;
    void openPicture();

public:
    explicit QOpenPictureWindow(Pixels*, QMain* mainWindow);


};

#endif //HOROSHOEDITOR_QOPENPICTUREWINDOW_H
