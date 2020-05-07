#include <iostream>
#include "Tank.hpp"

const char DEFAULT_SYM = 'T';

void Tank::draw() const
{
    std::cout << DEFAULT_SYM;
}


Coord Tank::move() const
{
    return { -1, 0 };
}
