#ifndef HOROSHOEDITOR_FILTRATIONENUM_H
#define HOROSHOEDITOR_FILTRATIONENUM_H

enum Filtration {
    NoFiltration,
    Threshold,
    OtsuThreshold,
    Median,
    Gaussian,
    LinearAveraging,
    Sobel,
    ContrastAdaptiveSharpening
};

#endif //HOROSHOEDITOR_FILTRATIONENUM_H
