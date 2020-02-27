#ifndef PLANET_HEADER_INCLUDED
#define PLANET_HEADER_INCLUDED

struct PlanetStruct
{
    char name[50];
    unsigned long long distance;
    unsigned long long diameter;
    unsigned long long mass;
};

PlanetStruct getPlanet(const char *name,
                 unsigned long long dist,
                 unsigned long long diam,
                 unsigned long long mass);

void printPlanet(PlanetStruct p);
#endif // PLANET_HEADER_INCLUDED
