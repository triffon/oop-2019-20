#include "ration.hpp"

int Rational::getA() const {
    return a;
}

int Rational::getB() const {
    return b;
}

Rational::Rational(int c, int d) {
    a = c;
    if(b == 0) {
        b = 1;
    } else {
        b = d;
    }
}
