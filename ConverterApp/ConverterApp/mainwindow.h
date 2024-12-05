#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLineEdit>
#include <QDoubleValidator>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private:
    QComboBox* unitTypeDropdown;

    QComboBox* leftUnitDropdown;
    QLineEdit* leftUnitInput;

    QComboBox* rightUnitDropdown;
    QLineEdit* rightUnitInput;
};

#endif // MAINWINDOW_H