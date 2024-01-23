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


int CheckValid(std::string str)
{
    
    return (0);
}

int CheckType(std::string str)
{
    if (str.length() == 1 && !isdigit(str[0]))
        return (1);
    else if (str.find('f') == (str.length() - 1) && str.find('.'))
        return (2);
    else if (str.find('.'))
        return (3);
    return (0);
}

void ScalarConverter::convert(std::string str)
{
    long long int n;
    char c;
    int i;
    float f;
    double d;

    if (CheckLimits(str))
        return;
    if (CheckValid(str))
        return;
    n = CheckType(str);
    if (n == 0)
    {
        i = atoi(str.c_str());
        c = static_cast<char>(i);
        f = static_cast<float>(i);
        d = static_cast<double>(i);
    }
    else if (n == 1)
    {
        c = str[0];
        i = static_cast<int>(c);
        f = static_cast<float>(c);
        d = static_cast<double>(c);
    }
    else if (n == 2)
    {
        f = atof(str.c_str());
        c = static_cast<char>(f);
        i = static_cast<int>(f);
        d = static_cast<double>(f);
    }
    else if (n == 3)
    {
        d = atof(str.c_str());
        i = static_cast<int>(d);
        c = static_cast<char>(d);
        f = static_cast<float>(d);
    }
    n = std::stoll(str);

    std::cout << "char: ";
    if (n < 127)
    {
        if (c < 32 || c > 126)
            std::cout << "Non displayable" << std::endl;
        else
            std::cout << "'" << c << "'" << std::endl;
    }
    else
        std::cout << "Overflow" << std::endl;

    std::cout << "int: ";
    if (n <= INT_MAX && n >= INT_MIN)
        std::cout << "'" << i << "'" << std::endl;
    else
        std::cout << "Overflow" << std::endl;
    std::cout << "float: ";
    if (n <= FLT_MAX && n >= FLT_MIN)
        std::cout << "'" << f << "'" << std::endl;
    else
        std::cout << "Overflow" << std::endl;
    std::cout << "double: ";
   if (n <= DBL_MAX && n >= DBL_MIN)
        std::cout << "'" << d << "'" << std::endl;
    else
        std::cout << "Overflow" << std::endl;
}