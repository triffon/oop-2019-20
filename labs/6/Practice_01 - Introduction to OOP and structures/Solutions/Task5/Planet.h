//
// Created by yasen on 2/22/20.
//

#ifndef TASK5_PLANET_H
#define TASK5_PLANET_H

#include <cstdlib>

typedef unsigned long long int ull_int;
#define NAME_SIZE (50)

struct Planet {
    char name[NAME_SIZE];
    ull_int distanceToSun;
    ull_int diameter;
    ull_int mass;
};

Planet enterPlanet();
void printPlanet(const Planet&);
ull_int secondToSum(const Planet&);
Planet* theClosestOneToSum(Planet planets[], size_t size);
void theClosestTwo(Planet planets[], size_t size, Planet& outFirst, Planet& outSecond);
void initPlanets(Planet*, size_t size);

#endif //TASK5_PLANET_H
