#ifndef ITERABLE_H
#define ITERABLE_H
#include "Iterator.h"
template<typename T>
class Iterable{
public:
    Iterator iter();
};
#endif