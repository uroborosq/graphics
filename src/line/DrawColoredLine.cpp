//
// Created by kotyangensss on 19.11.2022.
//

#include <cmath>
#include "DrawColoredLine.h"


float countTransparency(const float &transparency, double newPixel, const float &prevPixel) {
    return (float) newPixel * (1 - transparency) + prevPixel * transparency;
}

std::vector<float> &
DrawColoredLine::drawLine(Pixels *pixels, const int &width, const float &transparency,
                          const long long &startPixel,
                          const long long &lastPixel, std::vector<float> &color) {
    auto size = pixels->getValues().size();
    unsigned int colorSize = color.size();
    auto *newValues = new std::vector<float>(size);
    auto y0 = startPixel / pixels->getWidth();
    auto x0 = startPixel % pixels->getWidth();
    auto y1 = lastPixel / pixels->getWidth();
    auto x1 = lastPixel % pixels->getWidth();

    for (int i = 0; i < size; i++) {
        float &pixel = newValues->at(i);
        pixel = pixels->getValues()[i];
    }

    auto dx = abs(int(x1 - x0));
    auto dy = abs(int(y1 - y0));

    if (dy < dx) {
        double gradient = (float) dy / (float) dx;
        double intery1 = std::max((double) y0 + gradient - (int) (width / 2), 0.0);
        double intery2 = std::min(intery1 + width, (double) pixels->getHeight());

        for (long long x = x0 + 1; x1 - x0 > 0 ? x < x1 : x > x1; x1 - x0 > 0 ? x++ : x--) {
            for (int j = 0; j < colorSize; j++) {
                float &pixel = newValues->at(((long long) floor(intery1) * pixels->getWidth() + x) * colorSize + j);
                pixel = countTransparency(transparency, color[j] * (1 - (intery1 - floor(intery1))) +
                                                        newValues->at(
                                                                ((long long) floor(intery1) * pixels->getWidth() + x) *
                                                                colorSize +
                                                                j) *
                                                        (intery1 - floor(intery1)), pixels->getValues().at(
                        ((long long) floor(intery1) * pixels->getWidth() + x) * colorSize + j));
            }
            for (int j = 0; j < colorSize; j++) {
                float &pixel = newValues->at(((long long) floor(intery1 + 1) * pixels->getWidth() + x) * colorSize + j);
                pixel = countTransparency(transparency, color[j] * (intery1 - floor(intery1)) +
                                                        newValues->at(
                                                                ((long long) floor(intery1 + 1) * pixels->getWidth() +
                                                                 x) *
                                                                colorSize + j) *
                                                        (1 - intery1 + floor(intery1)), pixels->getValues().at(
                        ((long long) floor(intery1 + 1) * pixels->getWidth() + x) * colorSize + j));
            }
            intery1 = intery1 + gradient;

            for (int j = 0; j < colorSize; j++) {
                float &pixel = newValues->at(((long long) floor(intery2) * pixels->getWidth() + x) * colorSize + j);
                pixel = countTransparency(transparency, color[j] * (1 - (intery2 - floor(intery2))) +
                                                        newValues->at(
                                                                ((long long) floor(intery2) * pixels->getWidth() + x) *
                                                                colorSize +
                                                                j) *
                                                        (intery2 - floor(intery2)), pixels->getValues().at(
                        ((long long) floor(intery2) * pixels->getWidth() + x) * colorSize + j));
            }
            for (int j = 0; j < colorSize; j++) {
                float &pixel = newValues->at(((long long) floor(intery2 + 1) * pixels->getWidth() + x) * colorSize + j);
                pixel = countTransparency(transparency, color[j] * (intery2 - floor(intery2)) +
                                                        newValues->at(
                                                                ((long long) floor(intery2 + 1) * pixels->getWidth() +
                                                                 x) *
                                                                colorSize + j) *
                                                        (1 - intery2 + floor(intery2)), pixels->getValues().at(
                        ((long long) floor(intery2 + 1) * pixels->getWidth() + x) * colorSize + j));
            }
            intery2 = intery2 + gradient;

            for (long long it = (long long) floor(intery1) + 1; it <= (long long) floor(intery1 + width); it++) {
                for (int j = 0; j < colorSize; j++) {
                    float &pixel = newValues->at((long long) (it * pixels->getWidth() + x) * colorSize + j);
                    pixel = countTransparency(transparency, color[j], pixels->getValues().at(
                            (long long) (it * pixels->getWidth() + x) * colorSize + j));
                }
            }
        }
    } else {
        float gradient = (float) dx / (float) dy;

        double interx1 = std::max((double) x0 + gradient - (int) (width / 2), 0.0);
        double interx2 = std::min(interx1 + width, (double) pixels->getWidth());

        for (long long y = y0 + 1; y1 - y0 > 0 ? y < y1 : y > y1; y1 - y0 > 0 ? y++ : y--) {


            for (int j = 0; j < colorSize; j++) {
                float &pixel = newValues->at((y * pixels->getWidth() + (long long) floor(interx1)) * colorSize + j);
                pixel = countTransparency(transparency, color[j] * (1 - (interx1 - floor(interx1))) +
                                                        newValues->at(
                                                                (y * pixels->getWidth() + (long long) floor(interx1)) *
                                                                colorSize +
                                                                j) *
                                                        (interx1 - floor(interx1)), pixels->getValues().at(
                        (y * pixels->getWidth() + (long long) floor(interx1)) * colorSize + j));
            }
            for (int j = 0; j < colorSize; j++) {
                float &pixel = newValues->at((y * pixels->getWidth() + (long long) floor(interx1 + 1)) * colorSize + j);
                pixel = countTransparency(transparency, color[j] * (interx1 - floor(interx1)) +
                                                        newValues->at((y * pixels->getWidth() +
                                                                       (long long) floor(interx1 + 1)) *
                                                                      colorSize + j) *
                                                        (1 - interx1 + floor(interx1)), pixels->getValues().at(
                        (y * pixels->getWidth() + (long long) floor(interx1 + 1)) * colorSize + j));
            }
            interx1 = interx1 + gradient;

            for (int j = 0; j < colorSize; j++) {
                float &pixel = newValues->at((y * pixels->getWidth() + (long long) floor(interx2)) * colorSize + j);
                pixel = countTransparency(transparency, color[j] * (1 - (interx2 - floor(interx2))) +
                                                        newValues->at(
                                                                (y * pixels->getWidth() + (long long) floor(interx2)) *
                                                                colorSize +
                                                                j) *
                                                        (interx2 - floor(interx2)), pixels->getValues().at(
                        (y * pixels->getWidth() + (long long) floor(interx2)) * colorSize + j));
            }
            for (int j = 0; j < colorSize; j++) {
                float &pixel = newValues->at((y * pixels->getWidth() + (long long) floor(interx2 + 1)) * colorSize + j);
                pixel = countTransparency(transparency, color[j] * (interx2 - floor(interx2)) +
                                                        newValues->at((y * pixels->getWidth() +
                                                                       (long long) floor(interx2 + 1)) *
                                                                      colorSize + j) *
                                                        (1 - interx2 + floor(interx2)), pixels->getValues().at(
                        (y * pixels->getWidth() + (long long) floor(interx2 + 1)) * colorSize + j));
            }
            interx2 = interx2 + gradient;

            for (long long it = (long long) floor(interx1) + 1; it <= (long long) floor(interx1) + width; it++) {
                for (int j = 0; j < colorSize; j++) {
                    float &pixel = newValues->at((y * pixels->getWidth() + it) * colorSize + j);
                    pixel = countTransparency(transparency, color[j], pixels->getValues().at(
                            (y * pixels->getWidth() + it) * colorSize + j));
                }
            }
        }
    }
    return *newValues;
}
