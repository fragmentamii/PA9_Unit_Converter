#pragma once

#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QHash>
#include <typeinfo>
#include "Converter.hpp"
#include "ConstantConverter.hpp"

class ConverterWrapper
{
private:
	QHash<QString, Converter*> converters;
	QStringList categories;
public:
	ConverterWrapper();
	~ConverterWrapper();

	QStringList& getCategories();

	QHash<QString, Converter*>& getConverters();
	Converter*& getConverter(const QString& category);
};