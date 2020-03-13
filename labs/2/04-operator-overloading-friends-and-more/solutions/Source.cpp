#include <iostream>
#include "Vector.h"
#include "Virus.h"

int main()
{
    Vector vec;

    vec += Virus("Corona", 5);
    vec += Virus("The flu", 3);
    vec += Virus("Spanish flu", 6);
    vec += Virus("Corona B", 8);
    vec += Virus("Virus Z", 10);

    std::cout << vec << std::endl;
    vec.sort();
    std::cout << vec << std::endl;

    return 0;
}
