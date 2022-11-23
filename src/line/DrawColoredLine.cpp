//
// Created by kotyangensss on 19.11.2022.
//

#include <cmath>
#include "DrawColoredLine.h"


float countTransparency(const float &transparency, double newPixel, const float &prevPixel) {
    return (float) newPixel * (1 - transparency) + prevPixel * transparency;
}

std::vector<float> &DrawColoredLine::drawLine(std::vector<float> &pixels, const int& fileWidth, const int& fileHeight, const int &width, const float &transparency,
                          const long long &x0, const long long &y0, const long long &x1, const long long &y1, std::vector<float> &color) {

    auto size = pixels.size();
    unsigned int colorSize = color.size();
    auto *newValues = new std::vector<float>(size);

    for (int i = 0; i < size; i++) {
        float &pixel = newValues->at(i);
        pixel = pixels[i];
    }

    auto dx = int(x1 - x0);
    auto dy = int(y1 - y0);

    if (abs(dy) <= abs(dx)) {
        double gradient = (float) abs(dy) / abs(dx) * (dy / abs(dy));
        double intery1 = std::max((double) y0 + gradient - (int) (width / 2), 0.0);
        double intery2 = std::min(intery1 + width, (double) fileHeight);

        for (long long x = x0; x1 - x0 > 0 ? x < x1 : x > x1; x1 - x0 > 0 ? x++ : x--) {
            if (floor(intery1) > 0 && ceil(intery1) < fileHeight - 1) {
                for (int j = 0; j < colorSize; j++) {
                    float &pixel = newValues->at(((long long) floor(intery1) * fileWidth + x) * colorSize + j);
                    pixel = countTransparency(transparency, color[j] * (1 - (intery1 - floor(intery1))) +
                                                            newValues->at(
                                                                    ((long long) floor(intery1) * fileWidth + x) *
                                                                    colorSize +
                                                                    j) *
                                                            (intery1 - floor(intery1)), pixels.at(
                            ((long long) floor(intery1) * fileWidth + x) * colorSize + j));
                }
                for (int j = 0; j < colorSize; j++) {
                    float &pixel = newValues->at(((long long) floor(intery1 + 1) * fileWidth + x) * colorSize + j);
                    pixel = countTransparency(transparency, color[j] * (intery1 - floor(intery1)) +
                                                            newValues->at(
                                                                    ((long long) floor(intery1 + 1) * fileWidth +
                                                                     x) *
                                                                    colorSize + j) *
                                                            (1 - intery1 + floor(intery1)), pixels.at(
                            ((long long) floor(intery1 + 1) * fileWidth + x) * colorSize + j));
                }
            }

            if (floor(intery2) > 0 && ceil(intery2) < fileHeight) {
                for (int j = 0; j < colorSize; j++) {
                    float &pixel = newValues->at(((long long) floor(intery2) * fileWidth + x) * colorSize + j);
                    pixel = countTransparency(transparency, color[j] * (1 - (intery2 - floor(intery2))) +
                                                            newValues->at(
                                                                    ((long long) floor(intery2) * fileWidth + x) *
                                                                    colorSize +
                                                                    j) *
                                                            (intery2 - floor(intery2)), pixels.at(
                            ((long long) floor(intery2) * fileWidth + x) * colorSize + j));
                }
            }
            if (floor(intery2) > 0 && ceil(intery2) < fileHeight - 1) {
                for (int j = 0; j < colorSize; j++) {
                    float &pixel = newValues->at(((long long) floor(intery2 + 1) * fileWidth + x) * colorSize + j);
                    pixel = countTransparency(transparency, color[j] * (intery2 - floor(intery2)) +
                                                            newValues->at(
                                                                    ((long long) floor(intery2 + 1) * fileWidth +
                                                                     x) *
                                                                    colorSize + j) *
                                                            (1 - intery2 + floor(intery2)), pixels.at(
                            ((long long) floor(intery2 + 1) * fileWidth + x) * colorSize + j));
                }
            }

            for (long long it = std::max((long long) floor(intery1 + 1), (long long) 0);
                 it <= std::min((long long) floor(intery2), (long long) fileHeight - 1); it++) {
                for (int j = 0; j < colorSize; j++) {
                    float &pixel = newValues->at((long long) (it * fileWidth + x) * colorSize + j);
                    pixel = countTransparency(transparency, color[j], pixels.at(
                            (long long) (it * fileWidth + x) * colorSize + j));
                }
            }

            intery1 = intery1 + gradient;
            intery2 = intery2 + gradient;
        }
    } else {
        float gradient = (float) abs(dx) / abs(dy) * (dx / abs(dx));

        double interx1 = std::max((double) x0 + gradient - (int) (width / 2), 0.0);
        double interx2 = std::min(interx1 + width, (double) fileWidth);

        for (long long y = y0; y1 - y0 > 0 ? y < y1 : y > y1; y1 - y0 > 0 ? y++ : y--) {
            if (floor(interx1) > 0 && ceil(interx1) < fileWidth) {
                for (int j = 0; j < colorSize; j++) {
                    float &pixel = newValues->at((y * fileWidth + (long long) floor(interx1)) * colorSize + j);
                    pixel = countTransparency(transparency, color[j] * (1 - (interx1 - floor(interx1))) +
                                                            newValues->at(
                                                                    (y * fileWidth + (long long) floor(interx1)) *
                                                                    colorSize +
                                                                    j) *
                                                            (interx1 - floor(interx1)), pixels.at(
                            (y * fileWidth + (long long) floor(interx1)) * colorSize + j));
                }
            }
            if (floor(interx1) > 0 && ceil(interx1) < fileWidth - 1) {
                for (int j = 0; j < colorSize; j++) {
                    float &pixel = newValues->at((y * fileWidth + (long long) floor(interx1 + 1)) * colorSize + j);
                    pixel = countTransparency(transparency, color[j] * (interx1 - floor(interx1)) +
                                                            newValues->at((y * fileWidth +
                                                                           (long long) floor(interx1 + 1)) *
                                                                          colorSize + j) *
                                                            (1 - interx1 + floor(interx1)), pixels.at(
                            (y * fileWidth + (long long) floor(interx1 + 1)) * colorSize + j));
                }
            }
            if (floor(interx2) > 0 && ceil(interx2) < fileWidth) {
                for (int j = 0; j < colorSize; j++) {
                    float &pixel = newValues->at((y * fileWidth + (long long) floor(interx2)) * colorSize + j);
                    pixel = countTransparency(transparency, color[j] * (1 - (interx2 - floor(interx2))) +
                                                            newValues->at(
                                                                    (y * fileWidth + (long long) floor(interx2)) *
                                                                    colorSize +
                                                                    j) *
                                                            (interx2 - floor(interx2)), pixels.at(
                            (y * fileWidth + (long long) floor(interx2)) * colorSize + j));
                }
            }
            if (floor(interx2) > 0 && ceil(interx2) < fileWidth - 1) {
                for (int j = 0; j < colorSize; j++) {
                    float &pixel = newValues->at((y * fileWidth + (long long) floor(interx2 + 1)) * colorSize + j);
                    pixel = countTransparency(transparency, color[j] * (interx2 - floor(interx2)) +
                                                            newValues->at((y * fileWidth +
                                                                           (long long) floor(interx2 + 1)) *
                                                                          colorSize + j) *
                                                            (1 - interx2 + floor(interx2)), pixels.at(
                            (y * fileWidth + (long long) floor(interx2 + 1)) * colorSize + j));
                }
            }

            for (long long it = std::max((long long) floor(interx1), (long long) 0);
                 it <= std::min((long long) floor(interx2), (long long) fileWidth - 1); it++) {
                for (int j = 0; j < colorSize; j++) {
                    float &pixel = newValues->at((y * fileWidth + it) * colorSize + j);
                    pixel = countTransparency(transparency, color[j], pixels.at(
                            (y * fileWidth + it) * colorSize + j));
                }
            }

            interx1 = interx1 + gradient;
            interx2 = interx2 + gradient;
        }
    }
    return *newValues;
}
