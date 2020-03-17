#ifndef __RATIONAL_HPP__
#define __RATIONAL_HPP__

class Rational {

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

#endif