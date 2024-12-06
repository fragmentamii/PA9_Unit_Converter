#include "Converter.hpp"

void Converter::addOption(const QString option)
{
	options.append(option);
}

void Converter::setOptions(const QStringList options)
{
	this->options = options;
}

QStringList& Converter::getOptions()
{
	return options;
}
