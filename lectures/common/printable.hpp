#ifndef __PRINTABLE_HPP
#define __PRINTABLE_HPP

#include <iostream>

class Printable {
public:
    virtual void print(std::ostream& os = std::cout) const = 0;
    virtual ~Printable() {}
};
#endif