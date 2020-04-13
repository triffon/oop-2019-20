#ifndef __ANIMAL_HPP__
#define __ANIMAL_HPP__

#include "animal_type.hpp"

class Animal {

public:
    Animal();
    Animal(Animal const &);
    Animal & operator=(Animal const &);
    ~Animal();
    friend std::ostream& operator<<(std::ostream&, Animal&);
    void print();

    const char * getName();
    double getAge();
    AnimalType & getType();

    void setName(const char *);
    void setAge(double);
    void setType(AnimalType &);

private:
    char * name;
    double age;
    AnimalType type;
    void setNameFromString(const char *);

};

#endif