#ifndef CONVERTERWINDOW_H
#define CONVERTERWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLineEdit>

#include "ConverterWrapper.hpp"

class ConverterWindow : public QMainWindow
{
	Q_OBJECT;

public:
	explicit ConverterWindow(QWidget* parent = nullptr);

	~ConverterWindow();

public slots:
	void computeLeft(const QString& text);
	void computeRight(const QString& text);

private:
	QComboBox* categoryDropdown;
	QComboBox* leftDropdown;
	QComboBox* rightDropdown;

	QLineEdit* leftInput;
	QLineEdit* rightInput;

	QDoubleValidator* inputValidator;

	ConverterWrapper conversionObj;

	void initialize();
	void loadAppearance();
};

#endif // !CONVERTERWINDOW_H
