//
// Created by uroborosq on 18.12.22.
//

#ifndef HOROSHOEDITOR_FILEOPENDECIDER_H
#define HOROSHOEDITOR_FILEOPENDECIDER_H

#include "AbstractFile.h"
#include "FileFormat.h"

AbstractFile* getFileOpener(const std::string& path);
AbstractFile* getFileOpener(FileFormat format);

#endif //HOROSHOEDITOR_FILEOPENDECIDER_H
