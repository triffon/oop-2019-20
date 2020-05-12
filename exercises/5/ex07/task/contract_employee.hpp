#ifndef __CONTRACT_EMPLOYEE_HPP__
#define __CONTRACT_EMPLOYEE_HPP__

#include "employee.hpp"

class ContractEmployee : Employee {

public:
    ContractEmployee();
    ContractEmployee(ContractEmployee const &);
    ContractEmployee & operator=(ContractEmployee const &);
    ~ContractEmployee();

    double getMonthlyPayment() const;

private:
    double hours;

};

#endif