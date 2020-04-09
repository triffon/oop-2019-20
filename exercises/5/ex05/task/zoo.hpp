#ifndef __ZOO_HPP__
#define __ZOO_HPP__

#include "animal.hpp"

class Zoo {

public:
    Zoo();
    ~Zoo();
    Animal & get(int);
    void push(Animal &);
    int size() const; 
    double getPrice() const;
    void setPrice(double);
    friend std::ostream& operator<<(std::ostream&, Zoo&);
    void load(const char *);
    void save(const char *);

private:
    Animal * data;
    int count;
    int reserved;
    double price;
    const int INITIAL_RESERVED = 32;

};

#endif