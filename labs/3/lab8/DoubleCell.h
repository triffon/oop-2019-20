#ifndef DOUBLE_CELL_HEADER_INCLUDED
#define DOUBLE_CELL_HEADER_INCLUDED

#include "Cell.h"

class DoubleCell : public Cell
{
public:
    DoubleCell(double);
    void print() const;

private:
    double data;
};

#endif