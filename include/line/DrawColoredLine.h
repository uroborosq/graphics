//
// Created by optim on 19.11.2022.
//

#ifndef HOROSHOEDITOR_DRAWCOLOREDLINE_H
#define HOROSHOEDITOR_DRAWCOLOREDLINE_H

#include "AbstractDrawLine.h"

class DrawColoredLine : public AbstractDrawLine {
public:
    std::vector<float> &
    drawLine(std::vector<float> &pixels, const int &fileWidth, const int &fileHeight, const int &width,
             const float &transparency, const long long int &x0, const long long int &y0,
             const long long int &x1, const long long int &y1, std::vector<float> &color);
};

#endif //HOROSHOEDITOR_DRAWCOLOREDLINE_H
