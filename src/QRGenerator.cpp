#include "QRGenerator.h"
#include <QPainter>

QImage QRGenerator::generate(const QString &text, int scale)
{
    if (text.isEmpty()) return QImage();

    using qrcodegen::QrCode;
    try {
        QrCode qr = QrCode::encodeText(text.toUtf8().constData(), QrCode::Ecc::MEDIUM);
        
        int size = qr.getSize();
        int border = 2;
        int imgSize = (size + border * 2) * scale;
        
        QImage image(imgSize, imgSize, QImage::Format_ARGB32);
        image.fill(Qt::white);
        
        QPainter painter(&image);
        painter.setBrush(Qt::black);
        painter.setPen(Qt::NoPen);
        
        for (int y = 0; y < size; y++) {
            for (int x = 0; x < size; x++) {
                if (qr.getModule(x, y)) {
                    painter.drawRect((x + border) * scale, (y + border) * scale, scale, scale);
                }
            }
        }
        
        return image;
    } catch (...) {
        return QImage();
    }
}
