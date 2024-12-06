#pragma once

#include <QHash>

class Converter
{
protected:
	QString categoryName;
	QStringList options;
public:
	virtual double convert(double value, const QString& from, const QString& to) = 0;

	void addOption(const QString option);

	void setOptions(const QStringList options);
	QStringList& getOptions();
};