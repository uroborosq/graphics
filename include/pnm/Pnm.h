#ifndef CG22_PROJECT_HOROSHO_PNM_H
#define CG22_PROJECT_HOROSHO_PNM_H

#include <string>
#include <cstring>
#include <fstream>
#include <iostream>
#include <vector>


class Pnm {
public :
    int height;
    int width;
    int max;
    char tag[2];
    std::vector<uint8_t> data;
    Pnm();
    explicit Pnm(const std::string &path);
    void write(const std::string &path);
    void read(const std::string &path);
private:
    bool readTag(std::ifstream *ifstream);
};


#endif //CG22_PROJECT_HOROSHO_PNM_H
