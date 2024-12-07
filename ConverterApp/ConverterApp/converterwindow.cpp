#include "converterwindow.h"

ConverterWindow::ConverterWindow(QWidget* parent) : QMainWindow(parent)
{
	setWindowIcon(QIcon("converter_icon.png"));

	QWidget* centralWidget = new QWidget(this);
	setCentralWidget(centralWidget);

	initialize();
	loadAppearance();
}

ConverterWindow::~ConverterWindow()
{
}

void ConverterWindow::initialize()
{
	categoryDropdown = new QComboBox(this);
	categoryDropdown->setPlaceholderText("Select Category");
	categoryDropdown->addItems(conversionObj.getCategories());

	leftDropdown = new QComboBox(this);
	leftDropdown->setPlaceholderText("Select Unit");
	rightDropdown = new QComboBox(this);
	rightDropdown->setPlaceholderText("Select Unit");

	inputValidator = new QDoubleValidator(-1000.0, 1000.0, 5);

	leftInput = new QLineEdit(this);
	rightInput = new QLineEdit(this);

	leftInput->setValidator(inputValidator);
	rightInput->setValidator(inputValidator);

	QObject::connect(categoryDropdown, &QComboBox::currentTextChanged, [this](const QString& text) {
		leftDropdown->clear();
		rightDropdown->clear();

		leftDropdown->addItems(conversionObj.getConverter(text)->getOptions());
		rightDropdown->addItems(conversionObj.getConverter(text)->getOptions());
		});

	QObject::connect(leftInput, &QLineEdit::textEdited, this, &ConverterWindow::computeRight);
	QObject::connect(rightInput, &QLineEdit::textEdited, this, &ConverterWindow::computeLeft);
	QObject::connect(leftDropdown, &QComboBox::currentTextChanged, this, &ConverterWindow::computeRight);
	QObject::connect(rightDropdown, &QComboBox::currentTextChanged, this, &ConverterWindow::computeRight);
}

void ConverterWindow::loadAppearance()
{
	QLabel* label = new QLabel("=", this);
	label->setAlignment(Qt::AlignCenter);

	QWidget* centralWidget = new QWidget(this);
	setCentralWidget(centralWidget);

	QVBoxLayout* vBox = new QVBoxLayout();
	centralWidget->setLayout(vBox);

	vBox->addWidget(categoryDropdown);

	QWidget* unitInputArea = new QWidget(this);

	QGridLayout* grid = new QGridLayout();
	unitInputArea->setLayout(grid);

	grid->addWidget(leftInput, 0, 0);
	grid->addWidget(label, 0, 1);
	grid->addWidget(rightInput, 0, 2);
	grid->addWidget(leftDropdown, 1, 0);
	grid->addWidget(new QLabel(), 1, 1);
	grid->addWidget(rightDropdown, 1, 2);

	vBox->addWidget(unitInputArea);
}

void ConverterWindow::computeLeft(const QString& text)
{
	if (rightInput->text().isEmpty())
	{
		leftInput->setText("");
		return;
	}

	const QString& category = categoryDropdown->currentText();
	const QString& from = rightDropdown->currentText();
	const QString& to = leftDropdown->currentText();

	if (from.isEmpty() || to.isEmpty()) return;

	double value = rightInput->text().toDouble();
	double convertedValue = conversionObj.getConverter(category)->convert(value, from, to);

	leftInput->setText(QString::number(convertedValue));
}

void ConverterWindow::computeRight(const QString& text)
{
	if (leftInput->text().isEmpty())
	{
		rightInput->setText("");
		return;
	}

	const QString& category = categoryDropdown->currentText();
	const QString& from = leftDropdown->currentText();
	const QString& to = rightDropdown->currentText();

	if (from.isEmpty() || to.isEmpty()) return;

	double value = leftInput->text().toDouble();
	double convertedValue = conversionObj.getConverter(category)->convert(value, from, to);

	rightInput->setText(QString::number(convertedValue));
}
