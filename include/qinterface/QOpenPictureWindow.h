#ifndef HOROSHOEDITOR_QOPENPICTUREWINDOW_H
#define HOROSHOEDITOR_QOPENPICTUREWINDOW_H

#include <QWidget>
#include <QApplication>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include "Pnm.h"

class QOpenPictureWindow : public QWidget {
public:
    explicit QOpenPictureWindow(Pnm* file);
};

#endif //HOROSHOEDITOR_QOPENPICTUREWINDOW_H