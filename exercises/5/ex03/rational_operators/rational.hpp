#ifndef __RATIONAL_HPP__
#define __RATIONAL_HPP__

class Rational {

public:
    Rational(int, int);
    Rational operator+(Rational const &) const;
    Rational operator-(Rational const &) const;
    Rational operator*(Rational const &) const;
    Rational operator/(Rational const &) const;
    int getNom() const;
    int getDenom() const;

private:
    int nom;
    int denom;
    int gcd(int, int);

};

#endif