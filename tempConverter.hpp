//#pragma once
//
//#include <QDebug>
//
//#include "FunctionConverter.hpp"
//
//class TempConv : public FunctionConverter
//{
//public:
//	TempConv()
//	{
//		options = { "Fahrenheit", "Celsius", "Kelvin" };
//		fromFunctions["Fahrenheit"] = [](double value) { return (value - 32) * (5.0 / 9.0); };
//		fromFunctions["Celsius"] = [](double value) { return value; };
//		fromFunctions["Kelvin"] = [](double value) { return value - 273.15; };
//
//		toFunctions["Fahrenheit"] = [](double value) { return (value * 9 / 5) + 32; };
//		toFunctions["Celsius"] = [](double value) {return value; };
//		toFunctions["Kelvin"] = [](double value) {return value + 273.15; };
//	}
//
//	double convert(double value, const QString& from, const QString& to) override
//	{
//		FunctionConverter::convert(value, from, to);
//	}
//};