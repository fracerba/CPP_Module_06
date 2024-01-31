#include "Base.hpp"

Base::~Base()
{
}

Base *generate(void)
{
    int r = rand() % 3;
    if (r == 0)
    {
        std::cout << "Generato un puntatore di classe A" << std::endl;
        return (new A);
    }
    else if (r == 1)
    {
        std::cout << "Generato un puntatore di classe B" << std::endl;
        return (new B);
    }
    else if (r == 2)
    {
        std::cout << "Generato un puntatore di classe C" << std::endl;
        return (new C);
    }
    else
        return (NULL);
}

void identify(Base* p)
{
    if (!p)
        std::cout << "Identificato un puntatore NULL" << std::endl;
    else if (dynamic_cast<A*>(p))
        std::cout << "Identificato un puntatore di classe A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Identificato un puntatore di classe B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Identificato un puntatore di classe C" << std::endl;
    else
        std::cout << "Identificato un puntatore di classe Base" << std::endl;
}

void identify(Base& p)
{
    try
    {
        A &ref = dynamic_cast<A&>(p);
        (void)ref;
        std::cout << "Identificato un riferimento di classe A" << std::endl;
    }
    catch(const std::exception& e) {}
    try
    {
        B &ref = dynamic_cast<B&>(p);
        (void)ref;
        std::cout << "Identificato un riferimento di classe B" << std::endl;
    }
    catch(const std::exception& e) {}
    try
    {
        C &ref = dynamic_cast<C&>(p);
        (void)ref;
        std::cout << "Identificato un riferimento di classe C" << std::endl;
    }
    catch(const std::exception& e) {}
}