#include "Cell.h"
#include "IntCell.h"
#include "DoubleCell.h"

int main()
{
    Cell* c1 = new IntCell(5);
    Cell* c2 = new DoubleCell(5.34);
    c1->print();
    c2->print();
}