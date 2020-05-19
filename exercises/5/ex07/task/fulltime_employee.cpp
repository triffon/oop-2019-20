#include <cstring>
#include <iostream>

#include "fulltime_employee.hpp"

using std::cout;

FulltimeEmployee::FulltimeEmployee() {}

FulltimeEmployee::FulltimeEmployee(const char * _name, const char * _job, double _rate) : Employee(_name, _job, _rate) {};

FulltimeEmployee::FulltimeEmployee(FulltimeEmployee const & e) : Employee(e) {}

FulltimeEmployee & FulltimeEmployee::operator=(FulltimeEmployee const & e) {
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

FulltimeEmployee::~FulltimeEmployee() {}

double FulltimeEmployee::getWeeklyPayment() const {
    return 40 * rate;
}

void FulltimeEmployee::additionalInfo() const {
    cout << " * 40";
}
