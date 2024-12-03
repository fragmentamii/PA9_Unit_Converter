#pragma once
#include <string>

using std::string;


class Converter
{
public:
	virtual double unitConverter(string unitInput, string unitOutput, double value) = 0;
	virtual ~Converter() = default;
};