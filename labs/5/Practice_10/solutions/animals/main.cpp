#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Cow.hpp"
#include "Dog.hpp"
#include "Frog.hpp"

int main() {
    Animal animal;
    animal.sayHi();

    Cat cat;
    cat.sayHi();

    Dog dog;
    dog.sayHi();

    Frog frog;
    frog.sayHi();

    Cow cow;
    cow.sayHi();

    return 0;
}
