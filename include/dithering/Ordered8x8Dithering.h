//
// Created by uroborosq on 20.11.22.
//

#ifndef HOROSHOEDITOR_ORDERED8X8DITHERING_H
#define HOROSHOEDITOR_ORDERED8X8DITHERING_H

#include <vector>

class Ordered8x8Dithering
{
private:
    // код, достойный уважения
    int thresholdMatrix[64]{0, 48, 12, 60, 3, 51, 15, 63,
                            32, 16, 44, 28, 35, 19, 47, 31,
                            8, 56, 4, 52, 11, 59, 7, 55,
                            40, 24, 36, 20, 43, 27, 39, 23,
                            2, 50, 14, 62, 1, 49, 13, 61,
                            34, 18, 46, 30, 33, 17, 45, 29,
                            10, 58, 6, 54, 9, 57, 5, 53,
                            42, 26, 38, 22, 41, 25, 37, 21};
public:
     std::vector<float>& proceed(std::vector<float>& pixels, int width, int height);
};


#endif //HOROSHOEDITOR_ORDERED8X8DITHERING_H
