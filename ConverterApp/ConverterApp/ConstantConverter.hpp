#include <QFile>
#include <QHash>
#include <QString>
#include <stdexcept>
#include "Converter.hpp"

class ConstantConverter : public Converter
{
private:
	QHash<QString, double> conversionTable;
public:
	ConstantConverter(const QString categoryName);

	void loadTablesCsv(const QString fileName);

	double convert(double value, const QString from, const QString to) override;
};