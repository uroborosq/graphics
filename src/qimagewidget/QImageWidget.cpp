#include "QImageWidget.h"

QImageWidget::QImageWidget(std::vector<uint8_t> pixels, const int& height, const int& width, char* tag)
{
    auto image = QImage(width, height, QImage::Format_RGB888);

    if (tag[1] == '6') {
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                auto offset = i * width * 3 + j * 3;
                auto value = qRgb(pixels[offset], pixels[offset + 1], pixels[offset + 2]);
                image.setPixel(j, i, value);
            }
        }
    }
    else if (tag[1] == '5')
    {
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                auto offset = i * width + j;
                auto value = qRgb(pixels[offset], pixels[offset], pixels[offset]);
                image.setPixel(j, i, value);
            }
        }

    }
    auto pixmap = QPixmap::fromImage(image);
    setPixmap(pixmap);
}
