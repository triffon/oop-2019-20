#ifndef INT_CELL_HEADER_INCLUDED
#define INT_CELL_HEADER_INCLUDED

#include "Cell.h"

class IntCell : public Cell
{
public:
    IntCell(int);
    void print() const;

private:
    int data;
};

#endif