#include "FunctionConverter.hpp"

double FunctionConverter::convert(double value, const QString& from, const QString& to)
{
    if (fromFunctions.contains(from) && toFunctions.contains(to))
    {
        if (from == to) return value;
        return toFunctions[to](fromFunctions[from](value));
    }
    else throw std::runtime_error("Conversion unsupported");
}
