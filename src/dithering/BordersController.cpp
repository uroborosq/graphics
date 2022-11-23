//
// Created by uroborosq on 21.11.22.
//
#include "BordersController.h"

float checkBorders(const float& color) {
    return color <= 255 ? color < 0 ? 0 : color : 255;
}