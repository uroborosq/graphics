#ifndef HOROSHOEDITOR_QOPENPICTUREWINDOW_H
#define HOROSHOEDITOR_QOPENPICTUREWINDOW_H

#include <QWidget>
#include <QApplication>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <QComboBox>
#include <QFileDialog>
#include <QDialog>
#include "Pnm.h"
#include "QMain.h"


class QOpenPictureWindow : public QDialog {
private:
    QLineEdit* picturePath;
    QComboBox* colorspaces;
    bool isSubmitted;
    void openPicture();
    void findPicture();

public:
    explicit QOpenPictureWindow();
    std::string getPicturePath();
    bool checkSubmitted();
    ColorSpace getColorSpace();

};

#endif //HOROSHOEDITOR_QOPENPICTUREWINDOW_H
