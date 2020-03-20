#pragma once
#include <iostream>

class Rational
{
public:
    // Parameterized constructor with default values
    Rational(long long numerator = 0, long long denominator = 1);

    // Get methods
    long long getNumerator() const { return numer; }
    long long getDenominator() const { return denom; }

    // Set methods 
    //   they return Rational& so we can do this:
    //   rat.setNumerator(5).setDonimnator(7);
    Rational& setNumerator(long long numerator);
    Rational& setDenominator(long long numerator);

    // Unary -
    Rational operator-() const;
    // Reciprocal
    Rational operator~() const;

    // Algebraic assignment operators
    Rational& operator+=(const Rational& other);
    Rational& operator-=(const Rational& other);
    Rational& operator*=(const Rational& other);
    Rational& operator/=(const Rational& other);

    // Algebraic operators
    Rational operator+(const Rational& other) const;
    Rational operator-(const Rational& other) const;
    Rational operator*(const Rational& other) const;
    Rational operator/(const Rational& other) const;

    // ++Prefix
    Rational& operator++();
    // Postfix++
    Rational operator++(int);
    // --Prefix
    Rational& operator--();
    // Postfix--
    Rational operator--(int);

    // Comparison operators
    bool operator==(const Rational& other) const;
    bool operator<(const Rational& other) const;
    bool operator>=(const Rational& other) const;
    bool operator>(const Rational& other) const;
    bool operator<=(const Rational& other) const;

    // Input and output operators
    friend std::ostream& operator<<(std::ostream& out, const Rational& obj);
    friend std::istream& operator>>(std::istream& in, Rational& obj);

    // Conversion operators
    operator double() const;
    explicit operator float() const;

    // Simplify the fraction
    void simplify();

private:
    // Removes the minus signs if both numer and denom are negative
    // or sets the minus sign to the numerator instead of the denominator
    void fixNegation();

private:
    long long numer;
    long long denom;
};
