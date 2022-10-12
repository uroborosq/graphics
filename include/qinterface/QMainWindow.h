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
    QMainWindow(std::vector<uint8_t> pixels, const int& height, const int& width, char* tag);
};

#endif //HOROSHOEDITOR_QMAINWINDOW_H
