#include <QApplication>
#include "MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    app.setApplicationName("Liquid QR Coder");
    app.setOrganizationName("LiquidQR");

    MainWindow window;
    window.show();

    return app.exec();
}
