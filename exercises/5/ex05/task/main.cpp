#include <iostream>

#include "animal_type.hpp"
#include "animal.hpp"
#include "zoo.hpp"

int main() {
    AnimalType type1("Type 1", 57, safe);

    type1.print();
    std::cout << std::endl;

    Animal a1;
    a1.setName("Animal 1");
    a1.setAge(12);
    a1.setType(type1);

    Zoo zoo;
    zoo.setPrice(4.5);

    zoo.push(a1);

    a1.setName("New Animal 1");
    a1.setAge(11);
    zoo.push(a1);

    for (int i = 0; i < zoo.size(); ++i) {
        // cout << zoo[i];
        std::cout << i << ": ";
        zoo.get(i).print();
        std::cout << std::endl;
    }

    zoo.save("zoo.txt");

    Zoo zoo1;
    zoo1.load("zoo.txt");

    std::cout << zoo1;

    return 0;
}