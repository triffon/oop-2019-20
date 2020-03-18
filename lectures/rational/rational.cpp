#include <iostream>
#include <numeric>
#include "rational.hpp"
#include "rational.hpp"

void print() {
    std::cout << "Аз съм глобалната функция print()!\n";
}

// Rational::Rational() : denom(1), numer(0) {}

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
    std::clog << "Създавам ново рационално число: " << numer << "/" << denom << std::endl;
}

Rational::Rational(Rational const& r) : numer(r.numer), denom(r.denom) {
    std::clog << "Копираме числото " << r.numer << "/" << r.denom << std::endl;
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

Rational multiply(Rational const& p, Rational const& q) {
    return Rational(p.getNumerator() * q.getNumerator(),
                    p.getDenominator() * q.getDenominator());
}

Rational divide(Rational const& p, Rational const& q) {
    return Rational(p.getNumerator() * q.getDenominator(),
                    p.getDenominator() * q.getNumerator());
}

Rational add(Rational const& p, Rational const& q) {
    return Rational(p.getNumerator() * q.getDenominator() +
                    q.getNumerator() * p.getDenominator(),
                    p.getDenominator() * q.getDenominator());
}

Rational subtract(Rational const& p, Rational const& q) {
    return Rational(p.getNumerator() * q.getDenominator() -
                    q.getNumerator() * p.getDenominator(),
                    p.getDenominator() * q.getDenominator());
}