#ifndef ScalarConverter_HPP
#define ScalarConverter_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <climits>
#include <cfloat>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &New);
        ~ScalarConverter();
        ScalarConverter& operator=(const ScalarConverter &New);

    public:
        static void convert(std::string str);
};

#endif