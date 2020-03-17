#pragma once
#include "Vector.h"

const int MAX_NAME_LEN = 64;

class Person 
{
public:
    // Since we don't have dynamically allocated
    // memory there's no big four, just copy
    // constructor and operator= to correctly
    // copy the name of the person
    Person(const char* name = "", int age = 0);
    Person(const Person& other);
    Person& operator=(const Person& other);

    const char* getName() const { return name; }
    int getAge() const { return age; }
    const Vector& getViruses() const { return viruses; }

    void infect(const Virus& virus);

private:
    void copy(const Person& other);

    int age;
    char name[MAX_NAME_LEN];
    Vector viruses;
};
