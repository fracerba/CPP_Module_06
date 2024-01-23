#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout<<"ScalarConverter Default constructor called\n";
}

ScalarConverter::ScalarConverter(const ScalarConverter &New)
{
    *this = New;
	std::cout<<"ScalarConverter Copy constructor called\n";
}

ScalarConverter::~ScalarConverter()
{
	std::cout<<"ScalarConverter Destructor called\n";
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &New)
{
	std::cout<<"ScalarConverter Copy assignment operator called\n";
    (void)New;
	return(*this);
}

int CheckLimits(std::string str)
{
    if(str == "nan" || str == "nanf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return (1);
    }
    else if(str == "+inf" || str == "+inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
        return (1);
    }
    else if(str == "-inf" || str == "-inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
        return (1);
    }
    else
        return (0);
}

int CheckType(std::string str)
{
    if (str.length() == 1 && !isdigit(str[0]))
        return (1);
    else if (str.find('f') == (str.length() - 1) && str.find('.'))
        return (2);
    else if ()
        return (3);
    return (0);
}

void ScalarConverter::convert(std::string str)
{
    int n;

    if (CheckValid(str))
        return;
    if (CheckLimits(str))
        return;
    n = CheckType(str);
}