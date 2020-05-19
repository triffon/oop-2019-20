#ifndef __EMPLOYEE_HPP__
#define __EMPLOYEE_HPP__

class Employee {

public:
    Employee();
    Employee(const char *, const char *, double);
    Employee(Employee const &);
    Employee & operator=(Employee const &);
    ~Employee();

    virtual double getWeeklyPayment() const = 0;
    void info() const;
    virtual void additionalInfo() const = 0;

protected:
    double rate;
    char * name;
    char * job;

};

#endif