//
// Created by UroborosQ on 03.11.2022.
//

#ifndef HOROSHOEDITOR_ABSTRACTCOLORSPACE_H
#define HOROSHOEDITOR_ABSTRACTCOLORSPACE_H
#include <vector>

class AbstractColorSpace {
public:
    virtual std::vector<float>& to_rgb(std::vector<float>&)= 0;
    virtual std::vector<float>& from_rgb(std::vector<float>&)= 0;
};


#endif //HOROSHOEDITOR_ABSTRACTCOLORSPACE_H
