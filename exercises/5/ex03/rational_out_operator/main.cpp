#include <iostream>

#include "rational.hpp"

std::ostream & operator<<(std::ostream & out, Rational const & p) {
    out << p.getNom() << '/' << p.getDenom();

    return out;
}

int main() {
    Rational p(10, 15);

    std::cout << p << std::endl;

    Rational q(1, 2);

    Rational s1 = p + q;
    std::cout << s1 << std::endl;

    Rational s2 = p - q;
    std::cout << s2 << std::endl;

    Rational s3 = p * q;
    std::cout << s3 << std::endl;

    Rational s4 = p / q;
    std::cout << s4 << std::endl;

    return 0;
}
