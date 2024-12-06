#include <QApplication>
#include <QDebug>
#include "converterwindow.h"

// Responsible for launching the application

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    ConverterWindow mainWindow;
    mainWindow.setWindowTitle("Conversion App");
    mainWindow.resize(400, 300);  // Set initial size of the window
    mainWindow.show();

    return app.exec();
}
