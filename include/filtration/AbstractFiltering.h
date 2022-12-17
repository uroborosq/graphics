//
// Created by kotyangensss on 17.12.2022.
//

#ifndef HOROSHOEDITOR_ABSTRACTFILTERING_H
#define HOROSHOEDITOR_ABSTRACTFILTERING_H

#include <vector>

class AbstractFiltering
{
public:
    virtual std::vector<float>& filter(std::vector<float>& pixels) = 0;
};
#endif //HOROSHOEDITOR_ABSTRACTFILTERING_H
