#ifndef HOROSHOEDITOR_QSAVEPICTUREWINDOW_H
#define HOROSHOEDITOR_QSAVEPICTUREWINDOW_H

#include <QWidget>
#include <QApplication>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <QComboBox>
#include <QDialog>
#include "Pnm.h"
#include "Pixels.h"

class QSavePictureWindow : public QDialog {
public:
    explicit QSavePictureWindow();
    std::string getPicturePath();
    bool checkSubmitted();

private:
    QLineEdit* savePathLine;
    bool isSubmitted;
    void savePicture();

};

#endif //HOROSHOEDITOR_QSAVEPICTUREWINDOW_H
