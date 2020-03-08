//
// Created by yasen on 3/8/20.
//

#ifndef MARTA_SPROJECT_MARTENITSACONTAINER_H
#define MARTA_SPROJECT_MARTENITSACONTAINER_H


#include "Martenitsa.h"

class MartenitsaContainer {
public:
    MartenitsaContainer();

public:
    void add(const Martenitsa&);
    void print() const;
    void sort();

    inline size_t getSize() const { return size; };
    inline size_t getCapacity() const { return capacity; };
private:
    static const size_t capacity = 250;
    Martenitsa list[capacity];
    size_t size;
};


#endif //MARTA_SPROJECT_MARTENITSACONTAINER_H
