#pragma once

#include "BaseConverter.hpp"
#include "unordered_map"

using std::unordered_map;

class WeightConv : public Converter
{
public:
	double unitConverter(string inputUnit, string outputUnit, double value);

private:
	unordered_map<string, double> weightConvMap =
	{
		//base unit is Grams
		{"Milligram", .001},
		{"Gram", 1},
		{"Kilogram", 1000},
		{"Ounce", 28.35},
		{"Pound", 453.6}
	};
};

double WeightConv::unitConverter(string unitInput, string unitOutput, double value)
{
	auto inIndex = weightConvMap.find(unitInput);//Finds index in map of the name and conv factor of original unit
	auto outIndex = weightConvMap.find(unitOutput);//Finds index in map of the name and conv factor of new unit

	double inFactor = inIndex->second;
	double outFactor = outIndex->second;

	return (value * inFactor) / outFactor;
}