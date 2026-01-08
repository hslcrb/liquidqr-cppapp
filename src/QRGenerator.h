#ifndef QRGENERATOR_H
#define QRGENERATOR_H

#include <QImage>
#include <QString>
#include "qrcodegen.hpp"

class QRGenerator
{
public:
    static QImage generate(const QString &text, int scale = 10);
};

#endif // QRGENERATOR_H
