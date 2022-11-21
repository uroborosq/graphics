//
// Created by uroborosq on 21.11.22.
//
#include "DitheringMethodFactory.h"
#include "Ordered8x8Dithering.h"
#include "RandomDithering.h"
#include "FloydSteinbergDithering.h"
#include "AtkinsonDithering.h"

AbstractDithering *DitheringMethodFactory::create(Dithering dithering) {
    switch (dithering) {
        case Ordered8x8:
            return new Ordered8x8Dithering();
        case Random:
            return new RandomDithering();
        case FloydSteinberg:
            return new FloydSteinbergDithering();
        case Atkinson:
            return new AtkinsonDithering();
        case None:
            return nullptr;
    }
}
