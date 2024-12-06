#include "ConstantConverter.hpp"
#include <QDebug>

ConstantConverter::ConstantConverter(const QString& categoryName)
{
	this->categoryName = categoryName;
}

// Populates this class's conversion table with a .csv file
void ConstantConverter::loadTablesCsv(const QString& fileName)
{
	QFile tablesCsv(fileName);

	if (!tablesCsv.open(QIODevice::ReadOnly))
	{
		qDebug() << "Failed to open" << fileName;
	}

	QTextStream in(&tablesCsv);
	QStringList tokens;
	while (!in.atEnd())
	{
		tokens = in.readLine().split(',');
		// Adding to conversion table if category matches
		if (tokens.first() == categoryName)
		{
			options.append(tokens[1]);
			conversionTable[tokens[1]] = tokens[2].toDouble();
		}
	}

	qDebug() << conversionTable;

	tablesCsv.close();
}

void ConstantConverter::addConversion(const QString& unit, double value)
{
	conversionTable[unit] = value;
}

double ConstantConverter::convert(double value, const QString& from, const QString& to)
{
	// verify if units are in conversion table
	if (conversionTable.contains(from) && conversionTable.contains(to))
	{
		if (from == to) return value;
		return value * conversionTable[from] / conversionTable[to];
	}
	else throw std::runtime_error("Conversion unsupported");
}
