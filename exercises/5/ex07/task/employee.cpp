#include "employee.hpp"

Employee::Employee() {

}

Employee::Employee(Employee const & e) {

}

Employee & Employee::operator=(Employee const & e) {
    return *this;
}

Employee::~Employee() {

}

double Employee::getWeeklyPayment() const {
    return payment;
}