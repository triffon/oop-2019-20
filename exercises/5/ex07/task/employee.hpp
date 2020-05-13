#ifndef __EMPLOYEE_HPP__
#define __EMPLOYEE_HPP__

class Employee {

public:
    Employee();
    Employee(Employee const &);
    Employee & operator=(Employee const &);
    ~Employee();

    double getWeeklyPayment() const;

protected:
    double payment;
    char * name;

};

#endif