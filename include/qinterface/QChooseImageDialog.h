//
// Created by uroborosq on 25.11.22.
//

#ifndef HOROSHOEDITOR_QCHOOSEIMAGEDIALOG_H
#define HOROSHOEDITOR_QCHOOSEIMAGEDIALOG_H

#include <QDialog>
#include <QComboBox>

class QChooseImageDialog : public QDialog {
    bool isSubmitted = false;
    QComboBox* imageChooser;
    void chooseImage();
public:
    explicit QChooseImageDialog(const std::vector<std::string>&);
    bool checkSubmitted();
    std::string getChosenImage();

};

#endif //HOROSHOEDITOR_QCHOOSEIMAGEDIALOG_H
