#pragma once

/*
* The FunctionConverter class is for handling more complex conversions such as temperature.
* 
* It works by converting into the base unit, then into the target unit.
* 
* Intended to be inherited from.
*/

#include <QHash>
#include <QString>
#include <functional>
#include <stdexcept>
#include "Converter.hpp"

using convertFunction = std::function<double(double)>;

class FunctionConverter : public Converter
{
protected:
	QHash<QString, convertFunction> fromFunctions;
	QHash<QString, convertFunction> toFunctions;
public:
	
	double convert(double, const QString& from, const QString& to) override;
};