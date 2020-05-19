#include <cstring>
#include <iostream>

#include "employee.hpp"

using std::cout;

Employee::Employee() {
    name = nullptr;
    job = nullptr;
    rate = 0;
}

Employee::Employee(const char * _name, const char * _job, double _rate) : rate(_rate) {
    name = new char[strlen(_name) + 1];
    strcpy(name, _name);
    job = new char[strlen(_job) + 1];
    strcpy(job, _job);
}

Employee::Employee(Employee const & e) : rate(e.rate) {
    name = new char[strlen(e.name) + 1];
    strcpy(name, e.name);
    job = new char[strlen(e.job) + 1];
    strcpy(job, e.job);
}

Employee & Employee::operator=(Employee const & e) {
    if (&e != this) {
        delete[] name;
        delete[] job;
        name = new char[strlen(e.name) + 1];
        strcpy(name, e.name);
        job = new char[strlen(e.job) + 1];
        strcpy(job, e.job);
        rate = e.rate;
    }
    return *this;
}

Employee::~Employee() {
    delete[] name;
    delete[] job;
}

void Employee::info() const {
    cout << name << " - " << job << ": " << rate;
    additionalInfo();
}