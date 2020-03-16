#include <iostream>
#include <cassert>
#include "rational.hpp"
#include "utility.hpp"
using namespace std;

void Rational::simplify() {
    if (b < 0) {
        a = -a;
        b = -b;
    }

    int d = utility::gcd(a, b);
    a /= d;
    b /= d;
}

int Rational::getA() const {
    return a;
}

int Rational::getB() const {
    return b;
}

Rational::Rational(int a, int b): a(a), b(b) {
    assert(b != 0);
    simplify();
}

Rational Rational::operator+(const Rational& r2) {
    return Rational((a*r2.b + r2.a*b), b*r2.b);
}
Rational Rational::operator-(const Rational& r2) {
    return Rational((a*r2.b - r2.a*b), b*r2.b);
}
Rational Rational::operator*(const Rational& r2) {
    return Rational(a*r2.a, b*r2.b);
}
Rational Rational::operator/(const Rational& r2) {
    return Rational(a*r2.b, b*r2.a);
}

Rational& Rational::operator+=(const Rational& r2) {
    (*this) = (*this) + r2;
    return *this;
}

Rational& Rational::operator-=(const Rational& r2) {
    (*this) = (*this) - r2;
    return *this;
}

Rational& Rational::operator/=(const Rational& r2) {
    (*this) = (*this) / r2;
    return *this;
}

Rational Rational::operator-() {
    return Rational(-a, b);
}

void Rational::print() {
    cout << a;
    if (b != 1) {
        cout << "/" << b;
    }
}
