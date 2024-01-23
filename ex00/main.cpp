#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        if (argc == 1)
            std::cout << "Error: not enough arguments" << std::endl;
        else
            std::cout << "Error: too many arguments" << std::endl;
    }
    else
        ScalarConverter::convert(argv[1]);
    return (0);
}