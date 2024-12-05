#include "ConstantConverter.hpp"

ConstantConverter::ConstantConverter(const QString categoryName)
{
	this->categoryName = categoryName;
}

// Populates this class's conversion table with a .csv file
void ConstantConverter::loadTablesCsv(const QString fileName)
{
	QFile tablesCsv(fileName);
}

double ConstantConverter::convert(double value, const QString from, const QString to)
{
	if (conversionTable.contains(from) && conversionTable.contains(to))
	{
		return conversionTable[from] / conversionTable[to];
	}
	else throw std::runtime_error("Conversion unsupported");
}
