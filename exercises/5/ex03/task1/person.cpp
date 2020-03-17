#include <iostream>
#include <cstring>
#include "person.hpp"

Person::Person() {
    name = nullptr;
}

Person::Person(const char * _name, int _age, double _height, double _weight) {
    name = new char[strlen(_name)];
    strcpy(name, _name);
    age = _age;
    height = _height;
    weight = _weight;
}

Person::~Person() {
    delete name;
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
    delete name;
    name = new char[strlen(_name)];
    strcpy(name, _name);
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
