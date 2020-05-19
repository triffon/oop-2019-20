#include <cstring>
#include <iostream>

#include "contract_employee.hpp"

using std::cout;

ContractEmployee::ContractEmployee() : hours(0) {}

ContractEmployee::ContractEmployee(const char * _name, const char * _job, double _rate) : Employee(_name, _job, _rate), hours(0) {};

ContractEmployee::ContractEmployee(ContractEmployee const & e) : Employee(e), hours(e.hours) {}

ContractEmployee & ContractEmployee::operator=(ContractEmployee const & e) {
    if (&e != this) {
        delete[] name;
        delete[] job;
        name = new char[strlen(e.name) + 1];
        strcpy(name, e.name);
        job = new char[strlen(e.job) + 1];
        strcpy(job, e.job);
        rate = e.rate;
        hours = e.hours;
    }
    return *this;
}

ContractEmployee::~ContractEmployee() {}

double ContractEmployee::getWeeklyPayment() const {
    if (hours <= 40) {
        return hours * rate;
    } else if (hours <= 60) {
        return 1.5 * hours * rate;
    } else {
        return 2 * hours * rate;
    }
}

double ContractEmployee::getHours() const {
    return hours;
};

void ContractEmployee::setHours(double _hours) {
    hours = _hours;
};

void ContractEmployee::additionalInfo() const {
    cout << " * " << hours;
}
