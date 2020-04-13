#ifndef __COMPANY_HPP__
#define __COMPANY_HPP__

class Company {

private:
    char * name;
    int foundAge;
    int employeeCount;
    double capital;
    void setNameFromString(const char *); 

public:
    Company();
    Company(const char *, int, int, double);
    Company & operator=(Company const &);
    ~Company();
    double getCapital();
    void print();
};

#endif
