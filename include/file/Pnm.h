#ifndef CG22_PROJECT_HOROSHO_PNM_H
#define CG22_PROJECT_HOROSHO_PNM_H

#include <string>
#include <cstring>
#include <fstream>
#include <iostream>
#include <vector>

#include "AbstractFile.h"


class Pnm : public AbstractFile {
public:
    Pnm();
    void write(const std::string &path, const std::vector<float>&, FileImageInfo info) override;
    std::vector<float> read(const std::string &path) override;
    FileImageInfo getImageInfo() override;
    bool checkHeader(const char*) override;
private:
    FileImageInfo fileImageInfo;
};


#endif //CG22_PROJECT_HOROSHO_PNM_H
