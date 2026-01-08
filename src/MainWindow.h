#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include "LiquidBackground.h"

/**
 * @class MainWindow
 * @brief The main application window following Liquid Glassmorphism style
 *        Liquid Glassmorphism 스타일을 따르는 메인 애플리케이션 윈도우
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

protected:
    // Window dragging and resizing events / 창 드래그 및 리사이즈 이벤트
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void onTextChanged(const QString &text); // Text input handler / 텍스트 입력 핸들러
    void toggleLanguage();                   // Language switcher / 언어 전환용

private:
    void setupUi();
    void updateTexts();

    LiquidBackground *m_bg;
    QLineEdit *m_input;
    QLabel *m_qrLabel;
    QLabel *m_titleLabel;
    QLabel *m_subtitleLabel;
    QLabel *m_placeholderLabel;
    QPushButton *m_langBtn;

    QString m_lang;
    QPoint m_dragPos;
};

#endif // MAINWINDOW_H
