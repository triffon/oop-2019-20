#include <iostream>
#include <cstring>
#include "person.hpp"

int main() {
    char * nameIvan = new char[5];
    strcpy(nameIvan, "Ivan");

    Person p1;
    p1.setName(nameIvan);

    std::cout << p1.getName() << std::endl;

    nameIvan[0] = 'i';
    std::cout << p1.getName() << std::endl;

    delete nameIvan;
    std::cout << p1.getName() << std::endl;

    p1.setName("ivan");
    std::cout << p1.getName() << std::endl;

    Person p2("Gosho", 25, 1.75, 85);
    std::cout << p2.getName() << ' ' << p2.getAge() << ' ' << p2.getHeight() << ' ' << p2.getWeight() << std::endl;

    std::cout << p2 << std::endl;

    const char * name = p2.getName();

    std::cout << name << std::endl;

    //name[0] = 'g';
    std::cout << name << std::endl;
    std::cout << p2 << std::endl;

    std::cout << p2 << ", BMI: " << p2.getBMI() << std::endl;

    return 0;
}