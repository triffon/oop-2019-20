#include <iostream>
#include <cmath>
#include "rational.hpp"
#include "rational_point.hpp"

unsigned fact(unsigned n) {
    unsigned product = 1;
    for(unsigned i = 2; i <= n; i++)
        product *= i;
    return product;
}

Rational ratexp(unsigned k, unsigned n) {
    Rational sum;
    for(unsigned i = 0; i <= n; i++)
        // !!! sum += pow(k, i) / fact(i);
        // TODO: да се сметне общия член на редицата
        sum = add(sum, Rational(pow(k, i), fact(i)));
    return sum;
}

void testRationals() {
    // Rational r;
    Rational r(1, 2);
    Rational q = Rational(3, 4);
    Rational s = r;
    q.printnl();
    r.printnl();
    q = r;
    q.printnl();
    std::cout << q.toDouble() << std::endl;
    q.read();
    q.printnl();
    // !!! q.denom = 0;
    // q.printnl();
}

void testRatExp() {
    Rational r = ratexp(2, 14);
    r.printnl();
    std::cout << "r      = " << r.toDouble() << std::endl;
    std::cout << "exp(2) = " << exp(2) << std::endl;
    Rational r2 = r, r3 = 42;
    r3.printnl();
    r3 = r;
    add(42, Rational(1, 3)).printnl();
}

void testRationalPoint() {
    RationalPoint rp;
    rp.print();
    RationalPoint rp2(Rational(1, 3), Rational(2, 5));
    rp2.print();
    RationalPoint rp3 = rp2;
    rp3.print();
}

int main(int, char**) {
    // testRationals();
    // testRatExp();
    testRationalPoint();
}
