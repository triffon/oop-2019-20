// Голяма тройка:   деструктор, конструктор за копиране,
//                  предефиниран оператор за присвояване
// Голяма четворка: Голяма тройка + конструктор по подразбиране

#ifndef __RATIONAL_HPP__
#define __RATIONAL_HPP__

class Rational {

public:
    Rational();                             // конструктор по подразбиране
    Rational(Rational const &);             // конструктор за копиране
    Rational & operator=(Rational const &); // предефиниране на =
    ~Rational();                            // деструктор
    Rational(int, int);
    Rational operator+(Rational const &) const;
    Rational operator-(Rational const &) const;
    Rational operator*(Rational const &) const;
    Rational operator/(Rational const &) const;
    friend std::ostream & operator<<(std::ostream &, Rational const &);
    int getNom() const;
    int getDenom() const;

private:
    int nom;
    int denom;
    int gcd(int, int);

};

#endif