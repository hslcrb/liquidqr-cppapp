#ifndef QRGENERATOR_H
#define QRGENERATOR_H

#include <QImage>
#include <QString>
#include "qrcodegen.hpp"

/**
 * @class QRGenerator
 * @brief Utility class for QR Code generation using Nayuki's library
 *        Nayuki 라이브러리를 사용한 QR 코드 생성 유틸리티 클래스
 */
class QRGenerator
{
public:
    /**
     * @brief Generates a QR Code image from text / 텍스트로부터 QR 코드 이미지를 생성합니다
     * @param text The input content / 입력 내용
     * @param scale The pixel size per module / 모듈당 픽셀 크기
     * @return QImage of the QR Code / QR 코드 QImage
     */
    static QImage generate(const QString &text, int scale = 10);
};

#endif // QRGENERATOR_H
