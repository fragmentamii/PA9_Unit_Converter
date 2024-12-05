#include "Converter.hpp"

void Converter::setOptions(const QStringList options)
{
	this->options = options;
}

QStringList& Converter::getOptions()
{
	return options;
}
