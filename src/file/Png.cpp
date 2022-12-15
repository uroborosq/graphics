//
// Created by uroborosq on 14.12.22.
//

#include <fstream>
#include "Png.h"

std::vector<float> Png::read(const std::string &path) {
    std::ifstream input(path, std::ios::in | std::ios::binary);


}

void Png::write(const std::string &path, const std::vector<float> &pixels, FileImageInfo info) {

}

FileImageInfo Png::getImageInfo() {
    return FileImageInfo();
}
