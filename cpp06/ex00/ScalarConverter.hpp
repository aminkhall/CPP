#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <cctype>
#include <cstdlib>
#include <climits>
#include <iomanip>
#include <cmath>

enum type
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    UNKNOWN
};

class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter &operator=(const ScalarConverter &other);
    ~ScalarConverter();

public:
    static void convert(const std::string &);
};

#endif