#include <QApplication>
#include "MainWindow.h"

// Main entry point for the application / 애플리케이션의 메인 진입점
int main(int argc, char *argv[])
{
    // Initialize the Qt Application / Qt 애플리케이션 초기화
    QApplication app(argc, argv);

    // Set application metadata / 애플리케이션 메타데이터 설정
    app.setApplicationName("Liquid QR Coder");
    app.setOrganizationName("LiquidQR");

    // Create and show the main window / 메인 윈도우 생성 및 표시
    MainWindow window;
    window.show();

    // Start the application event loop / 애플리케이션 이벤트 루프 시작
    return app.exec();
}
