#ifndef __RATIONAL_POINT_HPP
#define __RATIONAL_POINT_HPP
#include <iostream>
#include "rational.hpp"

class RationalPoint {
    Rational x, y;

public:
    RationalPoint() /* : x(1, 1), y(2, 1) */ {}

    RationalPoint(Rational const& _x, Rational const& _y) : x(_x), y(_y) {}

//    RationalPoint(RationalPoint const& p) : x(p.x), y(p.y) {
        /*
        x = p.x;
        y = p.y;
        */
//    }

    Rational const& getX() const { return x; }
    Rational const& getY() const { return y; }

    void print() const {
        std::cout << "(";
        getX().print();
        std::cout << ",";
        getY().print();
        std::cout << ")" << std::endl;
    }
};

#endif