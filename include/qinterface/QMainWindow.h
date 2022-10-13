#ifndef HOROSHOEDITOR_QMAINWINDOW_H
#define HOROSHOEDITOR_QMAINWINDOW_H

#include <QWidget>
#include <QApplication>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>

class QMainWindow : public QWidget {
public:
    QMainWindow(const std::string& path);
};

#endif //HOROSHOEDITOR_QMAINWINDOW_H
