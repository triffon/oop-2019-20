//
// Created by yasen on 3/8/20.
//

#include "MartenitsaContainer.h"

MartenitsaContainer::MartenitsaContainer() : size(0) {
}

void MartenitsaContainer::add(const Martenitsa& newMartenitsa) {
    if(size < capacity) {
        list[size] = newMartenitsa; // operator= of class Martenitsa will be called
        ++size;
    }
}

void MartenitsaContainer::print() const {
    for (int i = 0; i < size; ++i) {
        list[i].print();
    }
}

void MartenitsaContainer::sort() {
    for (int i = 0; i < size-1; ++i) {
        size_t maxIndex = i;
        for (int j = i+1; j < size; ++j) {
            if(list[i].lessThen(list[j])) {
                maxIndex = j;
            }
        }
        if(maxIndex != i) {
            Martenitsa buff = list[i]; // Copy constuctor of class Martenitsa
            list[i] = list[maxIndex]; // operator= of class Martenitsa
            list[maxIndex] = buff; // operator= of class Martenitsa
        }
    }
}
