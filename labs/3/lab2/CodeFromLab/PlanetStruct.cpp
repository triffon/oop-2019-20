#include "PlanetStruct.h"
#include <string.h>
#include <iostream>

PlanetStruct getPlanet(const char *name,
                 unsigned long long dist,
                 unsigned long long diam,
                 unsigned long long mass)
{
    PlanetStruct result;
    strcpy(result.name, name);
    result.distance = dist;
    result.diameter = diam;
    result.mass = mass;

    return result;
}

void printPlanet(PlanetStruct p)
{
    std::cout << p.name << " "
              << p.distance << " "
              << p.diameter << " "
              << p.mass << std::endl;
}
