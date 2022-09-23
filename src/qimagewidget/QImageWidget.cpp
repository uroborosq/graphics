#include "QImageWidget.h"

QImageWidget::QImageWidget(int* pixels, const int& height,const int& width)
{

    auto image = QImage(width, height, QImage::Format_RGB32);

    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            auto offset = i * width * 3 + j * 3;
            auto value = qRgb(pixels[offset], pixels[offset + 1], pixels[offset + 2]);
            image.setPixel(j, i, value);
        }
    }

    auto pixmap = QPixmap::fromImage(image);
    setPixmap(pixmap);
}
