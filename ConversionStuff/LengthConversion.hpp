#pragma once

#include "BaseConverter.hpp"
#include <unordered_map>

using std::unordered_map;

class LengthConv : public Converter
{
public:
	double unitConverter(string unitInput, string unitOutput, double value);//Overloading explicit virtual function from base class
private:
	unordered_map<string, double> lengthConvMap =
	{
		//Base unit is meters(Convert everything to meters then to next unit)
		{"Micrometer", .000001},
		{"Millimeter", .001},
		{"Centimeter", .01},
		{"Meter", 1},
		{"Kilometer", 1000},
		{"Mile", 1609},
		{"Yard", 0.914076},
		{"Foot", 0.304785},
		{"Inch", 0.0254000}
	};
};

double LengthConv::unitConverter(string unitInput, string unitOutput, double value)
{
	auto inIndex = lengthConvMap.find(unitInput);//Finds index in map of the name and conv factor of original unit
	auto outIndex = lengthConvMap.find(unitOutput);//Finds index in map of the name and conv factor of new unit

	double inFactor = inIndex->second;
	double outFactor = outIndex->second;

	return (value * inFactor) / outFactor;//To guarantee no matter what direction we convert in the answer holds
}										//you have to multiply the value by the first conversion factor to put into meters, then divide by
										//the second conversion factor to make sure meters are cancelled.