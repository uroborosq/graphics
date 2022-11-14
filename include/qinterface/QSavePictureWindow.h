#ifndef HOROSHOEDITOR_QSAVEPICTUREWINDOW_H
#define HOROSHOEDITOR_QSAVEPICTUREWINDOW_H

#include <QWidget>
#include <QApplication>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <QComboBox>
#include "Pnm.h"

class QSavePictureWindow : public QWidget {
public:
    explicit QSavePictureWindow(Pnm* file);
};

#endif //HOROSHOEDITOR_QSAVEPICTUREWINDOW_H
