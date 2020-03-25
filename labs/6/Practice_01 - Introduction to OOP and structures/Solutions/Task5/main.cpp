#include <iostream>
#include "Planet.h"

int main() {
    Planet p1 = enterPlanet();
    printPlanet(p1);

    std::cout << "Seconds to Sun: " << secondToSum(p1) << std::endl;

    size_t size = 5;
    Planet planets[size];

    initPlanets(planets, size);

    Planet* closestToSun = theClosestOneToSum(planets, size);
    std::cout << "\nThe closest planet to the Sun is:" << std::endl;
    printPlanet(*closestToSun);

    Planet first, second;
    theClosestTwo(planets, size, first, second);
    std::cout << "\nThe two planets closest to each other is:" << std::endl;
    printPlanet(first);
    printPlanet(second);

    return 0;
}