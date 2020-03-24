#ifndef __PERSON_HPP__
#define __PERSON_HPP__

#include <iostream>

class Person {

public:
    Person();
    Person(const char *, int, double, double);
    Person(Person const &);
    Person & operator=(Person const &);
    ~Person();
    
    const char * getName() const;
    int getAge() const;
    double getHeight() const;
    double getWeight() const;

    void setName(const char *);
    void setAge(int);
    void setHeight(double);
    void setWeight(double);

    friend std::ostream & operator<<(std::ostream &, Person const &);

    double getBMI() const;

private:
    char * name;
    int age;
    double height;
    double weight;

    void setNameFromString(const char *);

};

#endif