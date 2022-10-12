#include "Pnm.h"

Pnm::Pnm(const std::string &path) {
    std::ifstream in(path, std::ios::in | std::ios::binary);
    if (in.fail()) {
        throw std::invalid_argument("FileNotFoundException");
    }
    if (readTag(&in)) {
        throw std::invalid_argument("wrong format");
    }
    char space;
    in.get(space);
    in >> width;
    in.get(space);
    in >> height;
    in.get(space);
    in >> max;
    in.get(space);
    data = std::vector<uint8_t>((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
}

bool Pnm::write(const std::string &path) {
    std::ofstream out(path, std::ios::out | std::ios::binary);
    if (out.is_open()) {
        out << tag << ' ' << width << ' ' << height << ' ' << max << ' ';
        for (char ch: data) {
            out << ch;
        }
    } else {
        return false;
    }
    return true;
}

bool Pnm::readTag(std::ifstream *in) {
    in->get(tag[0]);
    in->get(tag[1]);
    return !(tag[0] == 'P' && (tag[1] == '6' || tag[1] == '5'));
}

