#include "QImageWidget.h"
QImageWidget::QImageWidget(Pixels* pixels)
{
    auto height = pixels->getHeight();
    auto width = pixels->getWidth();
    std::vector<float> values = pixels->getValues();

    if (pixels->getColorSpace() != ColorSpace::RGB)
    {
       auto converter = chooseConverter(pixels->getColorSpace());
       values = converter->to_rgb(values);
    }

    auto image = QImage(pixels->getWidth(), pixels->getHeight(), QImage::Format_RGB888);

    if (pixels->getTag() == PnmFormat::P6) {
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                auto offset = i * width * 3 + j * 3;
                auto value = qRgb(uint_fast8_t(values[offset]), uint_fast8_t(values[offset + 1]), uint_fast8_t(values[offset + 2]));
                image.setPixel(j, i, value);
            }
        }
    }
    else if (pixels->getTag() == PnmFormat::P5)
    {
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                auto offset = i * width + j;
                auto pixel_value = uint_fast8_t(values[offset]);
                auto value = qRgb(pixel_value, pixel_value, pixel_value);
                image.setPixel(j, i, value);
            }
        }
    }
    auto pixmap = QPixmap::fromImage(image);
    setPixmap(pixmap);
}
