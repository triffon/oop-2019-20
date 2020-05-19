#ifndef __FULLTIME_EMPLOYEE_HPP__
#define __FULLTIME_EMPLOYEE_HPP__

#include "employee.hpp"

class FulltimeEmployee : public Employee {

public:
    FulltimeEmployee();
    FulltimeEmployee(const char *, const char *, double);
    FulltimeEmployee(FulltimeEmployee const &);
    FulltimeEmployee & operator=(FulltimeEmployee const &);
    ~FulltimeEmployee();

    double getWeeklyPayment() const;
    void additionalInfo() const;
};

#endif