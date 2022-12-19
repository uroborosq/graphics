//
// Created by UroborosQ on 19.12.2022.
//

#ifndef HOROSHOEDITOR_FILTERCONFIGURATION_H
#define HOROSHOEDITOR_FILTERCONFIGURATION_H

struct FilterConfiguration {
    int filterWidth;
    int filterHeight;
    int radius;
    float sharpness;
    float sigma;
    bool isUpper;
    float threshold;
};

#endif //HOROSHOEDITOR_FILTERCONFIGURATION_H
