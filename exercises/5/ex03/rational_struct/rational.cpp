#include "rational.hpp"

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

Rational Rational::add(Rational const & q) const {
    return Rational(nom * q.denom + q.nom * denom, denom * q.denom);
}

Rational Rational::substract(Rational const & q) const {
    return Rational(nom * q.denom - q.nom * denom, denom * q.denom);
}

Rational Rational::multiply(Rational const & q) const {
    return Rational(nom * q.nom, denom * q.denom);
}

Rational Rational::divide(Rational const & q) const {
    return Rational(nom * q.denom, denom * q.nom);
}