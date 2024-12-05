#include <QApplication>
#include <QDebug>
#include "mainwindow.h"

// Responsible for launching the application

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    MainWindow mainWindow;
    mainWindow.setWindowTitle("Conversion App");
    mainWindow.resize(400, 300);  // Set initial size of the window
    mainWindow.show();

    return app.exec();
}
