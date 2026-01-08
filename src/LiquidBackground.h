#ifndef LIQUIDBACKGROUND_H
#define LIQUIDBACKGROUND_H

#include <QWidget>
#include <QTimer>
#include <QVector>
#include <QPointF>

class LiquidBackground : public QWidget
{
    Q_OBJECT
public:
    explicit LiquidBackground(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    struct Blob {
        QPointF pos;
        QPointF velocity;
        double phase;
        QColor color;
    };
    QVector<Blob> m_blobs;
    QTimer *m_timer;
    double m_elapsed;
};

#endif // LIQUIDBACKGROUND_H
