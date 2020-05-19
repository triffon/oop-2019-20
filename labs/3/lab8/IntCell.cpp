#include <iostream>
#include "IntCell.h"

IntCell::IntCell(int x)
{
    data = x;
}

void IntCell::print() const
{
    std::cout << data << std::endl;
}