#ifndef Base_HPP
#define Base_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

class Base
{
    public:    
        virtual ~Base();
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base *generate(void);
void identify(Base* p);
void identify(Base& p);

#endif