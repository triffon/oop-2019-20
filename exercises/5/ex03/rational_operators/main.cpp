#include <iostream>

#include "rational.hpp"

int main() {
    Rational p(10, 15);

    std::cout << p.getNom() << '/' << p.getDenom() << std::endl;

    Rational q(1, 2);

    Rational s1 = p + q;
    std::cout << s1.getNom() << '/' << s1.getDenom() << std::endl;

    Rational s2 = p - q;
    std::cout << s2.getNom() << '/' << s2.getDenom() << std::endl;

    Rational s3 = p * q;
    std::cout << s3.getNom() << '/' << s3.getDenom() << std::endl;

    Rational s4 = p / q;
    std::cout << s4.getNom() << '/' << s4.getDenom() << std::endl;

    return 0;
}
