#include "ConverterWrapper.hpp"

ConverterWrapper::ConverterWrapper()
{
    // TODO: open file here
    QFile tablesCsv("tables.csv");

    if (!tablesCsv.open(QIODevice::ReadOnly))
    {
        qDebug() << "Failed to open \"tables.csv\"";
    }

    QTextStream in(&tablesCsv);
    QStringList tokens;
    ConstantConverter* constantConverter;

    // 0: category, 1: unit, 2: conversion

    // using polymorphism to create constant converters from .csv file
    while (!in.atEnd())
    {
        tokens = in.readLine().split(',');

        // adding a new key if not found
        if (!converters.contains(tokens.first()))
        {
            converters[tokens.first()] = new ConstantConverter(tokens.first());
            categories.append(tokens.first());
        }

        // casting to fully initialize converter
        constantConverter = dynamic_cast<ConstantConverter*>(converters[tokens.first()]);
        constantConverter->addOption(tokens[1]);
        constantConverter->addConversion(tokens[1], tokens[2].toDouble());
    }

    // TODO: add special converters below
}

ConverterWrapper::~ConverterWrapper()
{
    for (auto pair : converters)
    {
        delete(pair);
    }
}

QStringList& ConverterWrapper::getCategories()
{
    return categories;
}

QHash<QString, Converter*>& ConverterWrapper::getConverters()
{
    return converters;
}

Converter*& ConverterWrapper::getConverter(const QString& category)
{
    return converters[category];
}
