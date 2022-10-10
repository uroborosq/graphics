#include <iostream>
#include <random>
#include <QApplication>
#include "QImageWidget.h"


int main(int argc, char* argv[]) {
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    std::default_random_engine e;
    QApplication app(argc, argv);

    int height = 900;
    int width = 1600;
    auto pixels = (uint8_t*)calloc(height*width*3, 4);

    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            for (int z = 0; z < 3; ++z)
            {
                pixels[i * width * 3 + j * 3 + z] = e() % 256;
            }
        }
    }
    auto w = new QImageWidget(pixels, height, width);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << (end - begin) / pow(10, 9) << " это секунды такие";
    w->show();
    return QApplication::exec();
}
