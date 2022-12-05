//
// Created by uroborosq on 25.11.22.
//
#include <QPushButton>
#include <QHBoxLayout>
#include "QChooseImageDialog.h"

QChooseImageDialog::QChooseImageDialog(const std::vector<std::string> &imageNames) {
    imageChooser = new QComboBox();
    auto layout = new QHBoxLayout();
    auto size = imageNames.size();
    for (int i = 0; i < size; i++) {
        QString item = QString::fromStdString(imageNames[i]);
        imageChooser->addItem(item);
    }

    auto submit = new QPushButton("Подвердить");

    layout->addWidget(imageChooser);
    layout->addWidget(submit);

    setLayout(layout);

    connect(submit, &QPushButton::clicked, this, &QChooseImageDialog::chooseImage);
}

bool QChooseImageDialog::checkSubmitted() {
    return isSubmitted;
}

std::string QChooseImageDialog::getChosenImage() {
    return imageChooser->currentText().toStdString();
}

void QChooseImageDialog::chooseImage() {
    isSubmitted = true;
    close();
}
