//
// Created by uroborosq on 14.12.22.
//

#ifndef HOROSHOEDITOR_ABSTRACTFILE_H
#define HOROSHOEDITOR_ABSTRACTFILE_H

#include <vector>
#include <string>

#include "FileImageInfo.h"

class AbstractFile {
public:
    virtual std::vector<float> read(const std::string& path)= 0;
    virtual void write(const std::string& path, const std::vector<float>& pixels, FileImageInfo info)= 0;
    virtual FileImageInfo getImageInfo()= 0;
};

#endif //HOROSHOEDITOR_ABSTRACTFILE_H
