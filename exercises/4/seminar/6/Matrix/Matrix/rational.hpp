#include <iostream>
using namespace std;

#ifndef RATIONAL
#define RATIONAL

class Rational {
    int a;
    int b;

    void simplify();

public:

    int getA() const;
    int getB() const;

    Rational(int a = 0, int b = 1);

    Rational operator+(const Rational& r2);
    Rational operator-(const Rational& r2);
    Rational operator*(const Rational& r2);
    Rational operator/(const Rational& r2);

    Rational& operator+=(const Rational& r2);
    Rational& operator-=(const Rational& r2);
    Rational& operator/=(const Rational& r2);

    Rational operator-();

    void read(istream& in = cin);
    void print(ostream& out = cout) const;
};

istream& operator>>(istream& in, Rational& r);
ostream& operator<<(ostream& out, const Rational& r);

#endif
