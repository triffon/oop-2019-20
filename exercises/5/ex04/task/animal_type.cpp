#include <iostream>
#include <cstring>
#include "animal_type.hpp"

using std::cout;

AnimalType::AnimalType() {
    name = nullptr;
    lifetime = 0;
    status = safe;
}

AnimalType::AnimalType(const char * _name, double _lifetime, TypeStatus _status) {
    name = nullptr;
    setNameFromString(_name);
    lifetime = _lifetime;
    status = _status;
}

AnimalType::AnimalType(AnimalType const & at) {
    name = nullptr;
    setNameFromString(at.name);
    lifetime = at.lifetime;
    status = at.status;
}

AnimalType & AnimalType::operator=(AnimalType const & at) {
    setNameFromString(at.name);
    lifetime = at.lifetime;
    status = at.status;

    return *this;
}

AnimalType::~AnimalType() {
    delete[] name;
}

void AnimalType::print() {
    cout << (name ? name : "<unknown>") << " " << lifetime << " " << printStatus();
}

const char * AnimalType::printStatus() {
    switch (status) {
        case safe: return "Safe";
        case endangered: return "Endangered";
        case extinct: return "Extinct";
    }
}

void AnimalType::setNameFromString(const char * _name) {
    delete[] name;
    if (_name) {
        name = new char[strlen(_name) + 1];
        strcpy(name, _name);
    } else {
        name = nullptr;
    }
}