#include <iostream>
#include <numeric>
#include "rational.hpp"
#include "rational.hpp"

void print() {
    std::cout << "Аз съм глобалната функция print()!\n";
}

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

inline void Rational::print() const {
    // TODO: по желание да извежда q = преди числото
     std::cout << numer << '/' << denom;
}

void Rational::printnl() const {
    print();
    // ::print();
    std::cout << std::endl;
}

double Rational::toDouble() const {
    int numer = 5, denom = 2;
    // !!! this = &r;
    return (double)numer / denom;
}

void Rational::read() {
    // 1/2
    // int cin = 2;
    unsigned n;
    std::cin >> n;
    numer = n;
    int cin = 2;
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