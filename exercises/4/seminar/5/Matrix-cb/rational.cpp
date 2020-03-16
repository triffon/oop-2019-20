#include <iostream>
#include <cassert>
#include "rational.hpp"
#include "utility.hpp"
using namespace std;

void Rational::simplify() {
    int d = Utility::gcd(a, b);
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

void Rational::print() {
    cout<< a<< "/"<< b;
}
