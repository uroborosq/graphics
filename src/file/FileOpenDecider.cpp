//
// Created by uroborosq on 18.12.22.
//

#include "FileOpenDecider.h"
#include "Png.h"
#include "Pnm.h"
#include <fstream>
AbstractFile *getFileOpener(const std::string &path) {
    std::ifstream input (path, std::ios::in | std::ios::binary);

    if (input.fail())
        throw std::invalid_argument("File doesn't exist");

    auto header = new char[8];

    input.read(header, 8);
    auto png = new class Png();
    auto pnm = new class Pnm();
    if (png->checkHeader(header))
        return png;
    else if (pnm->checkHeader(header))
        return pnm;
    return nullptr;
}

AbstractFile *getFileOpener(FileFormat format) {
    switch (format) {
        case Pnm:
            return new class Pnm();
        case Png:
            return new class Png();
    }
}
