#include "LiquidBackground.h"
#include <QPainter>
#include <QRadialGradient>
#include <cmath>

LiquidBackground::LiquidBackground(QWidget *parent)
    : QWidget(parent), m_elapsed(0)
{
    // Initialize animated blobs with position, velocity, and color / 위치, 속도, 색상으로 애니메이션 블록(Blob) 초기화
    m_blobs << Blob{{0.2, 0.2}, {0.01, 0.015}, 0, QColor(255, 255, 255, 100)};
    m_blobs << Blob{{0.8, 0.8}, {-0.012, -0.008}, 1.5, QColor(144, 202, 249, 80)};
    m_blobs << Blob{{0.6, 0.1}, {0.005, 0.01}, 3.0, QColor(255, 255, 255, 60)};
    m_blobs << Blob{{0.3, 0.9}, {0.008, -0.012}, 4.5, QColor(129, 212, 250, 70)};

    // Start a 60FPS timer for smooth animation / 부드러운 애니메이션을 위한 60FPS 타이머 시작
    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, [this]() {
        m_elapsed += 0.016; // Approximately 60fps
        update();
    });
    m_timer->start(16);
}

/**
 * @brief Custom painting for the liquid effect / 리퀴드 효과를 위한 커스텀 페인팅
 */
void LiquidBackground::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Base gradient
    QLinearGradient base(0, 0, 0, height());
    base.setColorAt(0, QColor("#e1f5fe"));
    base.setColorAt(0.3, QColor("#b3e5fc"));
    base.setColorAt(0.7, QColor("#81d4fa"));
    base.setColorAt(1, QColor("#4fc3f7"));
    painter.fillRect(rect(), base);

    // Animated blobs
    for (int i = 0; i < m_blobs.size(); ++i) {
        auto &blob = m_blobs[i];
        double dx = 0.3 * std::sin(m_elapsed * 0.5 + blob.phase);
        double dy = 0.3 * std::cos(m_elapsed * 0.4 + blob.phase);
        
        double x = (blob.pos.x() + dx) * width();
        double y = (blob.pos.y() + dy) * height();
        double radius = width() * 0.6;

        QRadialGradient grad(x, y, radius);
        grad.setColorAt(0, blob.color);
        grad.setColorAt(1, Qt::transparent);
        
        painter.setBrush(grad);
        painter.setPen(Qt::NoPen);
        painter.drawEllipse(QPointF(x, y), radius, radius);
    }
}
