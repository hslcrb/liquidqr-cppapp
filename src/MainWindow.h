#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include "LiquidBackground.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void onTextChanged(const QString &text);
    void toggleLanguage();

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
