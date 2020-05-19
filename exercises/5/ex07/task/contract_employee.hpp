#ifndef __CONTRACT_EMPLOYEE_HPP__
#define __CONTRACT_EMPLOYEE_HPP__

#include "employee.hpp"

class ContractEmployee : public Employee {

public:
    ContractEmployee();
    ContractEmployee(const char *, const char *, double);
    ContractEmployee(ContractEmployee const &);
    ContractEmployee & operator=(ContractEmployee const &);
    ~ContractEmployee();

    double getWeeklyPayment() const;
    double getHours() const;
    void setHours(double);

    void additionalInfo() const;

private:
    double hours;

};

#endif