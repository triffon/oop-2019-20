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

    void print();
};

#endif
