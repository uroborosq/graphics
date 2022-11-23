//
// Created by uroborosq on 21.11.22.
//

#ifndef HOROSHOEDITOR_DITHERINGMETHODFACTORY_H
#define HOROSHOEDITOR_DITHERINGMETHODFACTORY_H

#include "AbstractDithering.h"
#include "DitheringEnum.h"

class DitheringMethodFactory {
public:
    static AbstractDithering* create(Dithering);
};

#endif //HOROSHOEDITOR_DITHERINGMETHODFACTORY_H
