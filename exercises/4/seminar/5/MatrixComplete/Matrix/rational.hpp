#ifndef RATIONAL
#define RATIONAL

class Rational {
    int a;
    int b;

    void simplify();

public:

    int getA() const;
    int getB() const;

    Rational(int c = 0, int d = 1);

    Rational operator-();

    Rational operator+(const Rational& r2);
    Rational operator-(const Rational& r2);
    Rational operator*(const Rational& r2);
    Rational operator/(const Rational& r2);

    void print();
};

#endif
