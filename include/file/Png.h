//
// Created by uroborosq on 14.12.22.
//

#ifndef HOROSHOEDITOR_PNG_H
#define HOROSHOEDITOR_PNG_H

#include "AbstractFile.h"

class Png : public AbstractFile {
public:
    std::vector<float> read(const std::string &path) override;
    void write(const std::string &path, const std::vector<float> &pixels, FileImageInfo info) override;
    FileImageInfo getImageInfo() override;
};

#endif //HOROSHOEDITOR_PNG_H
