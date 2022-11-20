//
// Created by optim on 19.11.2022.
//

#ifndef HOROSHOEDITOR_DRAWCOLOREDLINE_H
#define HOROSHOEDITOR_DRAWCOLOREDLINE_H

#include "AbstractDrawLine.h"

class DrawColoredLine : public AbstractDrawLine {
public:
    std::vector<float> &
    drawLine(std::vector<float> &pixels, const int &fileWidth, const int &fileHeight, const int &, const float &,
             const long long &, const long long &, const long long &, const long long &, std::vector<float> &) override;

};

#endif //HOROSHOEDITOR_DRAWCOLOREDLINE_H
