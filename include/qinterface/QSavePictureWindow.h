#ifndef HOROSHOEDITOR_QSAVEPICTUREWINDOW_H
#define HOROSHOEDITOR_QSAVEPICTUREWINDOW_H

#include <QWidget>
#include <QApplication>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>

class QSavePictureWindow : public QWidget {
public:
    QSavePictureWindow(std::string path);
};

#endif //HOROSHOEDITOR_QSAVEPICTUREWINDOW_H
