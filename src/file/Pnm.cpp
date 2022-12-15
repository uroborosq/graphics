#include "Pnm.h"

//Pnm::Pnm(const std::string &path) {
//    read(path);
//    }

//void Pnm::write(const std::string &path) {
//    std::ofstream out(path, std::ios::out | std::ios::binary);
//    if (out.is_open()) {
//        out << tag << ' ' << width << ' ' << height << ' ' << max << ' ';
//        for (float & ch: data) {
//            out << char(ch);
//        }
//    } else {
//        throw std::invalid_argument("Не получается получить доступ к файлу");
//    }
//}


std::vector<float> Pnm::read(const std::string &path) {

    std::ifstream in(path, std::ios::in | std::ios::binary);
    if (in.fail()) {
        throw std::invalid_argument("Файл не найден");
    }
    char tag[2];
    in.get(tag[0]);
    in.get(tag[1]);
    if (!(tag[0] == 'P' && (tag[1] == '6' || tag[1] == '5'))) {
        throw std::invalid_argument("Не удается открыть файл");
    }
    char space;
    fileImageInfo.fileFormat = tag[1] == '5' ? PnmP5 : PnmP6;
    fileImageInfo.channels = tag[1] == '5' ? 1 : 3;
    
    in.get(space);
    in >> fileImageInfo.width;
    in.get(space);
    in >> fileImageInfo.height;
    in.get(space);
    in >> fileImageInfo.pallet;
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

    if (info.fileFormat != PnmP5 && info.fileFormat != PnmP6) {
        throw std::invalid_argument("Pnm: полученный формат не равен Pnm");
    }

    std::ofstream out(path, std::ios::out | std::ios::binary);
    if (out.is_open()) {
        auto tag = info.fileFormat == FileFormat::PnmP5 ? "P5" : "P6";
        out << tag << ' ' << info.width << ' ' << info.height << ' ' << info.pallet << ' ';
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
