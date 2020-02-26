#include <iostream>
#include <numeric>
#include "rational.h"

Rational::Rational() {
    numer = 0;
    denom = 1;
}

Rational::Rational(long n, unsigned long d) {
    if (d == 0) {
        std::cerr << "Нулев знаменател, променям на 1" << std::endl;
        d = 1;
    }
    if (n == 0)
    d = 1;
    unsigned long g = std::gcd(std::abs(n), d);
    numer = n / g;
    denom = d / g;
}

void Rational::print() {
    // TODO: по желание да извежда q = преди числото
     std::cout << numer << '/' << denom;
}

void Rational::printnl() {
    print();
    std::cout << std::endl;
}

double Rational::toDouble() {
    return (double)numer / denom;
}

void Rational::read() {
    // 1/2
    // int cin = 2;
    std::cin >> numer;
    std::cin.get(); // прескачаме символа '/'
    std::cin >> denom;
    std::clog << "[LOG] numer = " << numer << std::endl;
    std::clog << "[LOG] denom = " << denom << std::endl;
}

Rational multiply(Rational p, Rational q) {
    return Rational(p.getNumerator() * q.getNumerator(),
                    p.getDenominator() * q.getDenominator());
}

Rational divide(Rational p, Rational q) {
    return Rational(p.getNumerator() * q.getDenominator(),
                    p.getDenominator() * q.getNumerator());
}

Rational add(Rational p, Rational q) {
    return Rational(p.getNumerator() * q.getDenominator() +
                    q.getNumerator() * p.getDenominator(),
                    p.getDenominator() * q.getDenominator());
}

Rational subtract(Rational p, Rational q) {
    return Rational(p.getNumerator() * q.getDenominator() -
                    q.getNumerator() * p.getDenominator(),
                    p.getDenominator() * q.getDenominator());
}