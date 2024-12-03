#pragma once

#include "BaseConverter.hpp"
#include <unordered_map>

using std::unordered_map;

class TempConv : public Converter
{
public:

	double farToCel(double value);//conversion functions
	double celToKel(double value);
	double kelToCel(double value);
	double celToFar(double value);
	double unitConverter(string unitInput, string unitOutput, double value);//Overloaded explicit virtual function from base class
private:
	unordered_map<string, double (TempConv::*)(double)> tempConvMap =//double (TempConv::*)(double) - the first double is the return type, (TempConv::*)
	{																//indicates that the function will be a pointer to a method of the TempConv class, 
		//base unit is Celsius										//the final double is the parameter of the function
		{"fToC", &TempConv::farToCel},
		{"cToK", &TempConv::celToKel},
		{"kToC", &TempConv::kelToCel},
		{"cToF", &TempConv::celToFar},
	};
};

double TempConv::farToCel(double value)
{
	return (value - 32) * (5.0 / 9.0);
}

double TempConv::celToKel(double value)
{
	return value + 273.15;
}

double TempConv::kelToCel(double value)
{
	return value - 273.15;
}

double TempConv::celToFar(double value)
{
	return (value * (9.0 / 5.0)) + 32;
}

double TempConv::unitConverter(string unitInput, string unitOutput, double value)
{
	auto inIndex = tempConvMap.find(unitInput);//Finds index in map of the name and conv factor of original unit
	auto outIndex = tempConvMap.find(unitOutput);//Finds index in map of the name and conv factor of new unit

	auto inFactor = inIndex->second;// Here the conversion factors are functions instead of numbers
	auto outFactor = outIndex->second;// We store the functions as the values of the map, and the conversions we are trying to accomplish is the key

	return (this->*outFactor)((this->*inFactor)(value));//We have to dereference the inFactor function pointer using ->* then use it as the parameter for the outFactor function pointer
}