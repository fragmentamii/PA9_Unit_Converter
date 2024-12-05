#include "ConverterWrapper.hpp"

ConverterWrapper::ConverterWrapper()
{
    // TODO: Open file here
}

QHash<QString, Converter*>& ConverterWrapper::getConverters()
{
    return converters;
}
