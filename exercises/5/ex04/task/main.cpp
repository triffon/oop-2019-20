#include <iostream>

#include "animal_type.hpp"
#include "animal.hpp"

int main() {
    AnimalType type1("Type 1", 57, safe);

    type1.print();
    std::cout << std::endl;

    Animal a1;
    a1.setName("Animal 1");
    a1.setAge(12);
    a1.setType(type1);

    a1.print();
    std::cout << std::endl;

    return 0;
}