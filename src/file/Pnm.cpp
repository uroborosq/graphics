#include <cmath>
#include "Pnm.h"

std::vector<float> Pnm::read(const std::string &path) {
    fileImageInfo = FileImageInfo{};
    std::ifstream in(path, std::ios::in | std::ios::binary);
    if (in.fail()) {
        throw std::invalid_argument("Файл не найден");
    }
    char tag[2];
    in.get(tag[0]);
    in.get(tag[1]);
    if (!checkHeader(tag)) {
        throw std::invalid_argument("Не удается открыть файл");
    }
    char space;
    fileImageInfo.fileFormat = tag[1] == '5' ? PnmP5 : PnmP6;
    fileImageInfo.channels = tag[1] == '5' ? 1 : 3;
    int depth;
    in.get(space);
    in >> fileImageInfo.width;
    in.get(space);
    in >> fileImageInfo.height;
    in.get(space);
    in >> depth;
    fileImageInfo.depth = (unsigned char)std::log2(depth + 1);
    in.get(space);


    auto size = fileImageInfo.height * fileImageInfo.width * (fileImageInfo.fileFormat == PnmP5 ? 1 : 3);
    auto data = std::vector<float>(size);
    std::size_t i = 0;
    while (!in.eof() && i < size)
    {
        in.get(space);
        data[i] = (float)(unsigned char)space;
        i++;
    }
    return data;
}

Pnm::Pnm() {
}

void Pnm::write(const std::string &path, const std::vector<float>& data, FileImageInfo info) {
    std::ofstream out(path, std::ios::out | std::ios::binary);
    if (out.is_open()) {
        auto tag = info.channels == 1 ? "P5" : "P6";
        out << tag << ' ' << info.width << ' ' << info.height << ' ' << (int)info.depth << ' ';
        for (const float & ch: data) {
            out << char(ch);
        }
    } else {
        throw std::invalid_argument("Не получается получить доступ к файлу");
    }
}

FileImageInfo Pnm::getImageInfo() {
    return fileImageInfo;
}

bool Pnm::checkHeader(const char *tag) {
    return (tag[0] == 'P' && (tag[1] == '6' || tag[1] == '5'));
}
