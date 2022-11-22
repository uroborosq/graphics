//
// Created by kotyangensss on 19.11.2022.
//

#ifndef HOROSHOEDITOR_ABSTRACTDRAWLINE_H
#define HOROSHOEDITOR_ABSTRACTDRAWLINE_H

#include "Pixels.h"

class AbstractDrawLine {
public:
    virtual std::vector<float> &
    drawLine(std::vector<float> &pixels, const int &fileWidth, const int &fileHeight, const int &, const float &,
             long long &, long long &, long long &, long long &,std::vector<float> &)= 0;
};

#endif //HOROSHOEDITOR_ABSTRACTDRAWLINE_H
