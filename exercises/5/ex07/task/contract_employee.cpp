#include "contract_employee.hpp"

ContractEmployee::ContractEmployee() {

}

ContractEmployee::ContractEmployee(ContractEmployee const & e) {

}

ContractEmployee & ContractEmployee::operator=(ContractEmployee const & e) {
    return *this;
}

ContractEmployee::~ContractEmployee() {

}

double ContractEmployee::getMonthlyPayment() const {
    return -1; ///payment;
}