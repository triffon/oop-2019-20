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

AnimalType::AnimalType(const char * _name, double _lifetime, const char * _status) {
    name = nullptr;
    setNameFromString(_name);
    lifetime = _lifetime;
    if (strcmp(_status, "Safe") == 0) {
        status = safe;
    } else if (strcmp(_status, "Endangered") == 0) {
        status = endangered;
    } else if (strcmp(_status, "Extinct") == 0) {
        status = extinct;
    }
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

std::ostream& operator<<(std::ostream& ostr, AnimalType& at) {
    ostr << (at.name ? at.name : "<unknown>") << " " << at.lifetime << " " << at.printStatus();
    return ostr;
}

void AnimalType::print() {
    cout << (*this);
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

const char * AnimalType::getName() {
    return name;
}

double AnimalType::getLifetime() {
    return lifetime;
}