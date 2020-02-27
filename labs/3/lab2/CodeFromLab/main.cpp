#include <iostream>
#include "PlanetStruct.h"
#include "PlanetClass.h"

int main()
{
    // Struct
    PlanetStruct ps;
    ps = getPlanet("Planet 1", 10000, 50, 500);
    printPlanet(ps);

    // Class
    PlanetClass p("Planet 2", 20000, 100, 1000);
    p.print();

    PlanetClass p1("Planet 3", 30000, 150, 1500);
    p1.print();

    return 0;
}
