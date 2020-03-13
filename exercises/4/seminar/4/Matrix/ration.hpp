#ifndef RATIONAL
#define RATIONAL

class Rational {
    int a;
    int b;

public:

    int getA() const;
    int getB() const;

    Rational(int c = 0, int d = 1);
};

#endif
