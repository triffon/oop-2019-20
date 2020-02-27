#include "PlanetClass.h"
#include <iostream>

void PlanetClass::print()
{
    std::cout << name << " "
              << distance << " "
              << diameter << " "
              << mass << std::endl;
}

PlanetClass::PlanetClass(const char* name
           , unsigned long long dist
           , unsigned long long diam
           , unsigned long long mass)
{
    strcpy(this->name, name);
        this->distance = dist;
        this->diameter = diam;
        this->mass = mass;
}
