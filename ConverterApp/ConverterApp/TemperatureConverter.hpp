#pragma once

#include "FunctionConverter.hpp"

class TemperatureConverter : public FunctionConverter
{
public:
	TemperatureConverter()
	{
		options = { "Celsius", "Fahrenheit", "Kelvin" };
		fromFunctions["Celsius"] = [](double value) { return value; };
		fromFunctions["Fahrenheit"] = [](double value) { return (value - 32) / 1.8; };
		fromFunctions["Kelvin"] = [](double value) { return value - 273.15; };
		toFunctions["Celsius"] = [](double value) { return value; };
		toFunctions["Fahrenheit"] = [](double value) { return (value * 1.8) + 32; };
		toFunctions["Kelvin"] = [](double value) { return value + 273.15; };
	};
};