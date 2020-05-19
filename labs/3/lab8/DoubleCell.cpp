#include <iostream>

#include "DoubleCell.h"

DoubleCell::DoubleCell(double x)
{
    data = x;
}

void DoubleCell::print() const
{
    std::cout << data << std::endl;
}