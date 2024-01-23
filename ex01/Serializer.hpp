#ifndef Serializer_HPP
#define Serializer_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <stdint.h>
#include "Data.hpp"

struct Data;

class Serializer
{
    private:
        Serializer();
        Serializer(const Serializer &New);
        ~Serializer();
        Serializer& operator=(const Serializer &New);

    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif