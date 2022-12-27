//
// Created by UroborosQ on 19.12.2022.
//
#include "FiltrationFabricMethod.h"
#include "ThresholdFiltering.h"
#include "MedianFiltering.h"
#include "OtsuThresholdFiltering.h"
#include "GaussianFiltering.h"
#include "CASFiltering.h"
#include "SobelFiltering.h"
#include "BoxBlurFiltering.h"

AbstractFiltering *getFiltrationByEnum(Filtration type) {
    switch (type) {
        case NoFiltration:
            return nullptr;
        case Threshold:
            return new ThresholdFiltering();
        case OtsuThreshold:
            return new OtsuThresholdFiltering();
        case Median:
            return new MedianFiltering();
        case Gaussian:
            return new GaussianFiltering();
        case LinearAveraging:
            return new BoxBlurFiltering();
        case Sobel:
            return new SobelFiltering();
        case ContrastAdaptiveSharpening:
            return new CASFiltering();
    }
}
