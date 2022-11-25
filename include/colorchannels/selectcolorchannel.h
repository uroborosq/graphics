//
// Created by uroborosq on 05.11.22.
//

#ifndef HOROSHOEDITOR_SELECTCOLORCHANNEL_H
#define HOROSHOEDITOR_SELECTCOLORCHANNEL_H

#include <vector>
#include "ColorChannelEnum.h"

std::vector<float> &select_color_channel(std::vector<float> &, const ColorChannel &);

std::vector<float> &remove_other_channels(std::vector<float> &, const ColorChannel &);

#endif //HOROSHOEDITOR_SELECTCOLORCHANNEL_H
