#include <QHash>
#include "Converter.hpp"

class ConverterWrapper
{
private:
	QHash<QString, Converter*> converters;
public:
	ConverterWrapper();
	~ConverterWrapper() = default;

	QHash<QString, Converter*>& getConverters();
};