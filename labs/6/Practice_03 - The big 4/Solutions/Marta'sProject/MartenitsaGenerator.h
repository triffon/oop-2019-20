//
// Created by yasen on 3/8/20.
//

#ifndef MARTA_SPROJECT_MARTENITSAGENERATOR_H
#define MARTA_SPROJECT_MARTENITSAGENERATOR_H


#include "MartenitsaContainer.h"

class MartenitsaGenerator {


public:
    MartenitsaGenerator(size_t = 0, size_t = 0);
public:
    Martenitsa generate();
    Martenitsa generateByName(const char* name);

    Martenitsa generateByWish(const char* wish);
    Martenitsa generateByNameAndWish(const char* name, const char* wish);
    void generateList(size_t count);
    void generateListByName(const char* name, size_t count);

    void generateListByWish(const char* wish, size_t count);
    void generateListByNameAndWish(const char* name, const char* wish, size_t count);

    MartenitsaContainer list;
private:
    size_t defaultLength;
    size_t defaultCountBeads;
};


#endif //MARTA_SPROJECT_MARTENITSAGENERATOR_H
