#include "Test.hpp"
#include <iostream>

using std::cout;

void Test::testConstantConverter()
{
	ConstantConverter Test("Length");
	Test.addConversion("Millimeters", 0.001);
	Test.addConversion("Centimeters", 0.01);
	double output = Test.convert(600, "Millimeters", "Centimeters");

	if (output != 60)
	{
		cout << "Constant conversion failed\n";
	}
	else
	{
		cout << "Constant conversion success\n";
	}
}

void Test::testFunctionConverter()
{
	TempConv Test;
	double output = Test.convert(42, "Fahrenheit", "Kelvin");
	if (output != 278.706)
	{
		cout << "Function conversion failed\n";
	}
	else
	{
		cout << "Function conversion success\n";
	}
}

void Test::testGetConvertertestGetOption()
{
	ConverterWrapper Test;
	Converter* VolumeConverter = Test.getConverter("Volume");
	qDebug() << VolumeConverter->getOptions();
}

void Test::testGetCategories()
{
	ConverterWrapper Test;
	QStringList categories = Test.getCategories();
	qDebug() << categories;
}