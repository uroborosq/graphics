//
// Created by kotyangensss on 19.11.2022.
//

#ifndef HOROSHOEDITOR_ABSTRACTDRAWLINE_H
#define HOROSHOEDITOR_ABSTRACTDRAWLINE_H

#include "Pixels.h"

class AbstractDrawLine{
public:
    virtual std::vector<float>& drawLine(Pixels*, const int&, const float&, const long long&, const long long&, std::vector<float>&);
};

#endif //HOROSHOEDITOR_ABSTRACTDRAWLINE_H
