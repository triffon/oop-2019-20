#ifndef PLANET_CLASS_HEADER_INCLUDED
#define PLANET_CLASS_HEADER_INCLUDED
#include <string.h>

class PlanetClass
{
private:
    char name[50];
    unsigned long long distance;
    unsigned long long diameter;
    unsigned long long mass;

public:
    PlanetClass(const char* name
           , unsigned long long dist
           , unsigned long long diam
           , unsigned long long mass);
    void print();

private:
    //...
};

#endif // PLANET_CLASS_HEADER_INCLUDED
