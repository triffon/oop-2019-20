#include <iostream>
#include "Beer.h"

int main()
{

    Beer beer1("Becks", 500);
    Beer beer2("Heineken", 500);

    beer1.addBeer(beer2, 250);

    std::cout << beer1.hasBrand("Heineken") << std::endl;
    std::cout << beer1.hasBrand("Hein") << std::endl;
    std::cout << beer1.hasBrand("Stella Artois") << std::endl;
    std::cout << beer1.hasBrand(beer2.getBrand()) << std::endl;

    return 0;
}
