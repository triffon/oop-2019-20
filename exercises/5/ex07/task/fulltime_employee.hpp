#ifndef __FULLTIME_EMPLOYEE_HPP__
#define __FULLTIME_EMPLOYEE_HPP__

#include "employee.hpp"

class FulltimeEmployee : Employee {

public:
    FulltimeEmployee();
    FulltimeEmployee(FulltimeEmployee const &);
    FulltimeEmployee & operator=(FulltimeEmployee const &);
    ~FulltimeEmployee();

};

#endif