#include "InterpolatinFabricMethod.h"
#include "BCSplinesInterpolation.h"
#include "BilinearInterpolation.h"
#include "LanczosInterpolation.h"
#include "NearestNeighbourInterpolation.h"

AbstractInterpolation *getInterpolationByEnum(Interpolation type) {
    switch (type) {
        case NoInterpolation:
            return nullptr;
        case BCSplines:
            return new BCSplinesInterpolation();
        case Bilinear:
            return new BilinearInterpolation();
        case Lanczos:
            return new LanczosInterpolation();
        case NearestNeighbour:
            return new NearestNeighbourInterpolation();
    }
}