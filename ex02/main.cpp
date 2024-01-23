#include "Base.hpp"

int main()
{
    Base *b;
    for (int i = 0; i < 10; i++)
    {
        if (i)
            std::cout << std::endl;
        b = generate();
        identify(b);
        identify(*b);
        delete b;
    }
    return (0);
}