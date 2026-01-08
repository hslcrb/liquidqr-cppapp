#include "MainWindow.h"
#include "QRGenerator.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMouseEvent>
#include <QApplication>
#include <QGraphicsBlurEffect>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), m_lang("ko")
{
    // Apply window flags for frameless and translucent style / 프레임리스 및 반투명 스타일 설정을 위한 윈도우 플래그 적용
    setWindowFlags(Qt::FramelessWindowHint | Qt::Window);
    setAttribute(Qt::WA_TranslucentBackground);
    setFixedSize(450, 700);
    // Set application icon from resources / 리소스에서 애플리케이션 아이콘 설정
    setWindowIcon(QIcon(":/icon.png"));

    setupUi();
}

/**
 * @brief Initialize the UI components / UI 컴포넌트 초기화
 */
void MainWindow::setupUi()
{
    QWidget *central = new QWidget(this);
    setCentralWidget(central);

    m_bg = new LiquidBackground(central);
    m_bg->lower();

    QVBoxLayout *mainLayout = new QVBoxLayout(central);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    // Custom Title Bar
    QWidget *titleBar = new QWidget(central);
    titleBar->setFixedHeight(40);
    titleBar->setStyleSheet("background: rgba(255, 255, 255, 60); border-bottom: 1px solid rgba(255, 255, 255, 40);");
    
    QHBoxLayout *titleLayout = new QHBoxLayout(titleBar);
    titleLayout->setContentsMargins(15, 0, 15, 0);
    
    QLabel *appTitle = new QLabel("Liquid QR Coder", titleBar);
    appTitle->setStyleSheet("color: #1976d2; font-weight: bold;");
    
    QPushButton *minBtn = new QPushButton(titleBar);
    minBtn->setFixedSize(12, 12);
    minBtn->setStyleSheet("QPushButton { background: #ffbd2e; border-radius: 6px; border: none; }");
    connect(minBtn, &QPushButton::clicked, this, &MainWindow::showMinimized);

    QPushButton *closeBtn = new QPushButton(titleBar);
    closeBtn->setFixedSize(12, 12);
    closeBtn->setStyleSheet("QPushButton { background: #ff5f56; border-radius: 6px; border: none; }");
    connect(closeBtn, &QPushButton::clicked, qApp, &QApplication::quit);

    titleLayout->addWidget(appTitle);
    titleLayout->addStretch();
    titleLayout->addWidget(minBtn);
    titleLayout->addWidget(closeBtn);

    mainLayout->addWidget(titleBar);

    // Content
    QWidget *content = new QWidget(central);
    QVBoxLayout *contentLayout = new QVBoxLayout(content);
    contentLayout->setContentsMargins(30, 40, 30, 40);
    contentLayout->setSpacing(30);

    m_titleLabel = new QLabel(content);
    m_titleLabel->setAlignment(Qt::AlignCenter);
    m_titleLabel->setStyleSheet("font-size: 32px; font-weight: 900; color: #1976d2;");

    m_subtitleLabel = new QLabel(content);
    m_subtitleLabel->setAlignment(Qt::AlignCenter);
    m_subtitleLabel->setStyleSheet("font-size: 14px; color: #42a5f5;");

    m_input = new QLineEdit(content);
    m_input->setFixedHeight(55);
    m_input->setStyleSheet(
        "QLineEdit {"
        "  background: rgba(255, 255, 255, 120);"
        "  border: 1px solid rgba(255, 255, 255, 180);"
        "  border-radius: 25px;"
        "  padding: 0 20px;"
        "  font-size: 16px;"
        "  color: #1976d2;"
        "  font-weight: bold;"
        "}"
        "QLineEdit:focus {"
        "  background: rgba(255, 255, 255, 180);"
        "  border: 1px solid #1976d2;"
        "}"
    );
    connect(m_input, &QLineEdit::textChanged, this, &MainWindow::onTextChanged);

    QFrame *glass = new QFrame(content);
    glass->setFixedHeight(350);
    glass->setStyleSheet(
        "QFrame {"
        "  background: rgba(255, 255, 255, 50);"
        "  border: 1px solid rgba(255, 255, 255, 100);"
        "  border-radius: 35px;"
        "}"
    );
    
    QVBoxLayout *glassLayout = new QVBoxLayout(glass);
    m_qrLabel = new QLabel(glass);
    m_qrLabel->setAlignment(Qt::AlignCenter);
    m_qrLabel->setStyleSheet("border: none; background: white; border-radius: 15px; margin: 20px;");
    m_qrLabel->hide();

    m_placeholderLabel = new QLabel(glass);
    m_placeholderLabel->setAlignment(Qt::AlignCenter);
    m_placeholderLabel->setStyleSheet("color: #81c784; font-size: 14px; border: none; background: transparent;");

    glassLayout->addWidget(m_qrLabel);
    glassLayout->addWidget(m_placeholderLabel);

    m_langBtn = new QPushButton(content);
    m_langBtn->setFixedSize(100, 40);
    m_langBtn->setStyleSheet(
        "QPushButton {"
        "  background: rgba(255, 255, 255, 120);"
        "  border-radius: 20px;"
        "  color: #1976d2;"
        "  font-weight: bold;"
        "  border: 1px solid rgba(255, 255, 255, 80);"
        "}"
        "QPushButton:hover { background: rgba(255, 255, 255, 180); }"
    );
    connect(m_langBtn, &QPushButton::clicked, this, &MainWindow::toggleLanguage);

    contentLayout->addWidget(m_titleLabel);
    contentLayout->addWidget(m_subtitleLabel);
    contentLayout->addWidget(m_input);
    contentLayout->addWidget(glass);
    contentLayout->addWidget(m_langBtn, 0, Qt::AlignCenter);

    mainLayout->addWidget(content);
    
    updateTexts();
}

void MainWindow::updateTexts()
{
    if (m_lang == "ko") {
        m_titleLabel->setText("실시간 QR 생성기");
        m_subtitleLabel->setText("입력과 동시에 QR 코드가 생성됩니다");
        m_input->setPlaceholderText("텍스트를 입력하세요...");
        m_placeholderLabel->setText("위에 텍스트를 입력하면\nQR 코드가 나타납니다");
        m_langBtn->setText("English");
    } else {
        m_titleLabel->setText("Live QR Generator");
        m_subtitleLabel->setText("QR code generates as you type");
        m_input->setPlaceholderText("Enter text here...");
        m_placeholderLabel->setText("QR code will appear\nwhen you type above");
        m_langBtn->setText("한국어");
    }
}

void MainWindow::onTextChanged(const QString &text)
{
    if (text.isEmpty()) {
        m_qrLabel->hide();
        m_placeholderLabel->show();
    } else {
        QImage img = QRGenerator::generate(text, 8);
        m_qrLabel->setPixmap(QPixmap::fromImage(img).scaled(300, 300, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        m_qrLabel->show();
        m_placeholderLabel->hide();
    }
}

void MainWindow::toggleLanguage()
{
    m_lang = (m_lang == "ko" ? "en" : "ko");
    updateTexts();
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && event->pos().y() < 40) {
        m_dragPos = event->globalPosition().toPoint() - frameGeometry().topLeft();
        event->accept();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton && event->pos().y() < 60) {
        move(event->globalPosition().toPoint() - m_dragPos);
        event->accept();
    }
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
    if (m_bg) m_bg->resize(size());
}
