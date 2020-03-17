#include <iostream>

struct Rational {

public:
    Rational(int, int);
    Rational add(Rational const &) const;
    Rational substract(Rational const &) const;
    Rational multiply(Rational const &) const;
    Rational divide(Rational const &) const;
    int getNom() const;
    int getDenom() const;

private:
    int nom;
    int denom;
    int gcd(int, int);

};

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

int main() {
    Rational p(10, 15);

    std::cout << p.getNom() << '/' << p.getDenom() << std::endl;

    Rational q(1, 2);

    Rational s1 = p.add(q);
    std::cout << s1.getNom() << '/' << s1.getDenom() << std::endl;

    Rational s2 = p.substract(q);
    std::cout << s2.getNom() << '/' << s2.getDenom() << std::endl;

    Rational s3 = p.multiply(q);
    std::cout << s3.getNom() << '/' << s3.getDenom() << std::endl;

    Rational s4 = p.divide(q);
    std::cout << s4.getNom() << '/' << s4.getDenom() << std::endl;

    return 0;
}
