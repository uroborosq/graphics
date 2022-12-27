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
#include "FileFormat.h"
class QSavePictureWindow : public QDialog {
public:
    QComboBox* formatList;
    explicit QSavePictureWindow();
    std::string getPicturePath();
    bool checkSubmitted();
    FileFormat getFormat();
private:
    QLineEdit* savePathLine;
    bool isSubmitted;
    void savePicture();

};

#endif //HOROSHOEDITOR_QSAVEPICTUREWINDOW_H
