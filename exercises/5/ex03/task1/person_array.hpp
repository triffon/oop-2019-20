#ifndef __PERSON_ARRAY_HPP__
#define __PERSON_ARRAY_HPP__

#include "person.hpp"

class PersonArray {

public:
    PersonArray();
    ~PersonArray();
    void push(Person &);
    Person & get(int);
    int size();

private:
    Person * data;
    int count;
    int reservedCount;

};

#endif