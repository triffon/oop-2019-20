#include <iostream>
#include <cstring>
#include "person.hpp"

Person::Person() {
    name = nullptr;
}

Person::Person(Person const & p) {
    name = nullptr;
    setNameFromString(p.name);
    age = p.age;
    height = p.height;
    weight = p.weight;
}

Person & Person::operator=(Person const & p) {
    setNameFromString(p.name);
    age = p.age;
    height = p.height;
    weight = p.weight;

    return *this;
}

Person::Person(const char * _name, int _age, double _height, double _weight) {
    name = nullptr;
    setNameFromString(_name);
    age = _age;
    height = _height;
    weight = _weight;
}

Person::~Person() {
    delete[] name;
}

const char * Person::getName() const {
    return name;
}

int Person::getAge() const {
    return age;
}

double Person::getHeight() const {
    return height;
}

double Person::getWeight() const {
    return weight;
}

void Person::setName(const char * _name) {
    setNameFromString(_name);
}

void Person::setAge(int _age) {
    age = _age;
}

void Person::setHeight(double _height) {
    height = _height;
}

void Person::setWeight(double _weight) {
    weight = _weight;
}

std::ostream & operator<<(std::ostream & out, Person const & p) {
    out << p.name << ": " << p.age << " years, " << p.height << " m, " << p.weight << " kg";
}

double Person::getBMI() const {
    return weight / (height * height);
}

void Person::setNameFromString(const char * _name) {
    delete[] name;
    name = new char[strlen(_name) + 1];
    strcpy(name, _name);
}