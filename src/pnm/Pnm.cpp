#include "Pnm.h"

Pnm::Pnm(const std::string &path) {
    read(path);
    }

void Pnm::write(const std::string &path) {
    std::ofstream out(path, std::ios::out | std::ios::binary);
    if (out.is_open()) {
        out << tag << ' ' << width << ' ' << height << ' ' << max << ' ';
        for (uint8_t ch: data) {
            out << ch;
        }
    } else {
        throw std::invalid_argument("Не получается получить доступ к файлу");
    }
}

bool Pnm::readTag(std::ifstream *in) {
    in->get(tag[0]);
    in->get(tag[1]);
    return !(tag[0] == 'P' && (tag[1] == '6' || tag[1] == '5'));
}

void Pnm::read(const std::string &path) {
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

Pnm::Pnm() {
height = -1;
width = -1;
data = std::vector<uint8_t>();
}
