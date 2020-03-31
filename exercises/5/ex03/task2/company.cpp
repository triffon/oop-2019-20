#include <iostream>
#include <cstring>
#include "company.hpp"

using std::cout;

Company::Company() {
    name = nullptr;
    foundAge = 0;
    employeeCount = 0;
    capital = 0;
}

Company::Company(const char * temp_name, int temp_foundAge, int temp_employeeCount, double temp_capital) {
    name = nullptr;
    setNameFromString(temp_name);
    foundAge = temp_foundAge;
    employeeCount = temp_employeeCount;
    capital = temp_capital;
}

Company & Company::operator=(Company const & c) {
    setNameFromString(c.name);
    foundAge = c.foundAge;
    employeeCount = c.employeeCount;
    capital = c.capital;
    return *this;
}

Company::~Company() {
    delete[] name;
}

double Company::getCapital() {
  return capital;
}

void Company::print() {
    cout << name << " " << foundAge << " " << employeeCount << " " << capital;
}

void Company::setNameFromString(const char * _name) {
    delete[] name;
    name = new char[strlen(_name) + 1];
    strcpy(name, _name);
}