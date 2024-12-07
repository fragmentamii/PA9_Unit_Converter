#include <QApplication>
#include <QDebug>
#include "converterwindow.h"
#include "test.hpp"

// Responsible for launching the application

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    ConverterWindow mainWindow;
    mainWindow.setWindowTitle("Conversion App");
    mainWindow.resize(400, 300);  // Set initial size of the window
    mainWindow.show();

    //Test tester;
    //tester.testConstantConverter();
    //tester.testFunctionConverter();
    //tester.testGetCategories();
    //tester.testGetConvertertestGetOption();

    return app.exec();
}
