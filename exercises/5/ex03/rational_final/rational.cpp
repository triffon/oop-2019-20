#include <iostream>
#include "rational.hpp"

Rational::Rational() {
    nom = 0;
    denom = 1;
}

Rational::Rational(Rational const & p) {
    nom = p.nom;
    denom = p.denom;
}

Rational & Rational::operator=(Rational const & p) {
    nom = p.nom;
    denom = p.denom;

    return *this;
}

Rational::~Rational() {

}

int Rational::gcd(int a, int b) {
    if (a == b) return a;
    if (a > b) return gcd(a - b, b);
    return gcd(a, b - a);
}

Rational::Rational(int _a, int _b) {
    int g = gcd(_a, _b);
    nom = _a / g;
    denom = _b / g;
}

int Rational::getNom() const {
    return nom;
}

int Rational::getDenom() const {
    return denom;
}

Rational Rational::operator+(Rational const & q) const {
    return Rational(nom * q.denom + q.nom * denom, denom * q.denom);
}

Rational Rational::operator-(Rational const & q) const {
    return Rational(nom * q.denom - q.nom * denom, denom * q.denom);
}

Rational Rational::operator*(Rational const & q) const {
    return Rational(nom * q.nom, denom * q.denom);
}

Rational Rational::operator/(Rational const & q) const {
    return Rational(nom * q.denom, denom * q.nom);
}

std::ostream & operator<<(std::ostream & out, Rational const & p) {
    out << p.nom << '/' << p.denom;

    return out;
}