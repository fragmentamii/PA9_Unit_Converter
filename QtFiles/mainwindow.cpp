#include "mainwindow.h"

#include <string>

// Responsible for displaying gui elements

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent)
{
	QDoubleValidator* doubleValidator = new QDoubleValidator(0.0, 1000.0, 2, this);

	unitTypeDropdown = new QComboBox(this);
	unitTypeDropdown->setGeometry(100, 50, 200, 50);
	unitTypeDropdown->setPlaceholderText("Select Category");

	unitTypeDropdown->clear();
	unitTypeDropdown->addItems({ "Length", "Mass", "Temperature" });

	leftUnitInput = new QLineEdit(this);
	leftUnitInput->setGeometry(0, 150, 100, 25);
	leftUnitInput->setValidator(doubleValidator);

	leftUnitDropdown = new QComboBox(this);
	leftUnitDropdown->setGeometry(0, 200, 100, 25);
	leftUnitDropdown->setPlaceholderText("Select Unit");

	rightUnitInput = new QLineEdit(this);
	rightUnitInput->setGeometry(300, 150, 100, 25);
	rightUnitInput->setValidator(doubleValidator);

	rightUnitDropdown = new QComboBox(this);
	rightUnitDropdown->setGeometry(300, 200, 100, 25);
	rightUnitDropdown->setPlaceholderText("Select Unit");

	QObject::connect(unitTypeDropdown, &QComboBox::currentTextChanged, [this](const QString& text) {
		leftUnitDropdown->clear();
		rightUnitDropdown->clear();
		if (text.compare("Length") == 0)
		{
			leftUnitDropdown->addItems({ "Meters", "Kilometers", "Centimeters" });
			rightUnitDropdown->addItems({ "Meters", "Kilometers", "Centimeters" });
		}
		if (text.compare("Mass") == 0)
		{
			leftUnitDropdown->addItems({ "Grams", "Kilograms", "Milligrams" });
			rightUnitDropdown->addItems({ "Grams", "Kilograms", "Milligrams" });
		}
		if (text.compare("Temperature") == 0)
		{
			leftUnitDropdown->addItems({ "Fahrenheit ", "Celsius", "Kelvin" });
			rightUnitDropdown->addItems({ "Fahrenheit", "Celsius", "Kelvin" });
		}
		});
}

MainWindow::~MainWindow()
{
}

