#include <iostream>

#include "rational.hpp"

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

    Rational z1;
    std::cout << "z1: " << z1 << std::endl;

    Rational z2(p);
    std::cout << "z2: " << z2 << std::endl;

    z1 = p;
    std::cout << "z1: " << z1 << std::endl;

    p = z1 * q;
    std::cout << z1 << ' ' << p << std::endl;

    return 0;
}
