#include <iostream>
#include <cstring>

#include "animal_type.hpp"
#include "animal.hpp"

Animal::Animal() {
    name = nullptr;
    age = 0;
    type = AnimalType();
}

Animal::Animal(Animal const & a) {
    name = nullptr;
    setNameFromString(a.name);
    age = a.age;
    type = a.type;
}

Animal & Animal::operator=(Animal const & a) {
    setNameFromString(a.name);
    age = a.age;
    type = a.type;

    return *this;
}

Animal::~Animal() {
    delete[] name;
}

std::ostream& operator<<(std::ostream& ostr, Animal& a) {
    ostr << (a.name ? a.name : "<unknown>") << " " << a.age << " type: " << a.type;
    return ostr;
}

void Animal::print() {
    std::cout << (*this);
}

const char * Animal::getName() {
    return name;
}

double Animal::getAge() {
    return age;
}

AnimalType & Animal::getType() {
    return type;
}

void Animal::setName(const char * _name) {
    setNameFromString(_name);
}

void Animal::setAge(double _age) {
    age = _age;
}

void Animal::setType(AnimalType & _type) {
    type = _type;
}

void Animal::setNameFromString(const char * _name) {
    delete[] name;
    if (_name) {
        name = new char[strlen(_name) + 1];
        strcpy(name, _name);
    } else {
        name = nullptr;
    }
}