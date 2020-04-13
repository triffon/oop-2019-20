#ifndef __ARRAY_HPP__
#define __ARRAY_HPP__

#include "company.hpp"

class Array {

private:
  Company * data;
  int count;
  int reservedCount;

public:
    Array();
    ~Array();
    void push(Company &);
    Company & get(int);
    int size();
};

#endif
