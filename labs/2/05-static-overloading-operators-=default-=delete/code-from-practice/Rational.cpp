#include <numeric>  // for std::gcd
#include <cmath>    // for std::abs
#include "Rational.h"


Rational::Rational(long long numerator, long long denominator)
    : numer(numerator)
    , denom(denominator)
{
    simplify();
}


Rational& Rational::setNumerator(long long numerator)
{
    numer = numerator;
    simplify();
    return *this;
}


Rational& Rational::setDenominator(long long denominator)
{
    denom = denominator;
    simplify();
    return *this;
}


Rational Rational::operator-() const
{
    return Rational(-numer, denom);
}


Rational Rational::operator~() const
{
    return Rational(denom, numer);
}


Rational& Rational::operator+=(const Rational& other)
{
    // A lot of infinity and "not a number" checks
    if ((numer == 0 && denom == 0) || (other.numer == 0 && other.denom == 0)) {
        numer = 0;
        denom = 0;
    } else if (denom == 0 && other.denom != 0) {
        numer = numer < 0 ? -1 : 1;
    } else if (other.denom == 0 && denom != 0) {
        denom = 0;
        numer = other.numer < 0 ? -1 : 1;
    } else if (denom == 0 && other.denom == 0) {
        if (numer * other.numer < 0)
            numer = 0;
        else
            numer = numer < 0 ? -1 : 1;
    } else {
        // Actual addition of rational numbers
        numer = numer * other.denom + other.numer * denom;
        denom *= other.denom;
        simplify();
    }
    return *this;
}


Rational& Rational::operator-=(const Rational& other)
{
    return *this += -other;
}


Rational& Rational::operator*=(const Rational& other)
{
    numer *= other.numer;
    denom *= other.denom;
    simplify();
    return *this;
}


Rational& Rational::operator/=(const Rational& other)
{
    if (other.numer != 0) {
        // Just multiply by the reciprocal
        *this *= ~other;
    } else {
        // Division by 0
        if (other.denom != 0 && numer != 0) {
            numer = numer < 0 ? -1 : 1;
            denom = 0;
        } else {
            denom = 0;
        }
    }
    return *this;
}


Rational Rational::operator+(const Rational& other) const
{
    return Rational(*this) += other;
}


Rational Rational::operator-(const Rational& other) const
{
    return Rational(*this) -= other;
}


Rational Rational::operator*(const Rational& other) const
{
    return Rational(*this) *= other;
}


Rational Rational::operator/(const Rational& other) const
{
    return Rational(*this) /= other;
}


Rational& Rational::operator++()
{
    numer += denom;
    simplify();
    return *this;
}


Rational Rational::operator++(int)
{
    Rational res(*this);
    ++*this;
    return res;
}


Rational& Rational::operator--()
{
    numer -= denom;
    simplify();
    return *this;
}


Rational Rational::operator--(int)
{
    Rational res(*this);
    --*this;
    return res;
}


bool Rational::operator==(const Rational& other) const
{
    return numer == other.numer && denom == other.denom;
}


bool Rational::operator<(const Rational& other) const
{
    if (denom * other.denom < 0)
        return numer * other.denom > other.numer * denom;
    else
        return numer * other.denom < other.numer * denom;
}


bool Rational::operator>=(const Rational& other) const
{
    return !(*this < other);
}


bool Rational::operator>(const Rational& other) const
{
    if (denom * other.denom < 0)
        return numer * other.denom < other.numer * denom;
    else
        return numer * other.denom > other.numer * denom;
}


bool Rational::operator<=(const Rational& other) const
{
    return !(*this > other);
}


std::ostream& operator<<(std::ostream& out, const Rational& obj)
{
    if (obj.denom != 0) {
        if (obj.numer == 0) {
            // Zero check
            out << obj.numer;
        } else {
            Rational res(obj);
            res.fixNegation();
            if (res.denom == 1) // Whole num check
                out << res.numer;
            else
                out << res.numer << "/" << res.denom;
        }
    } else {
        // Division by zero
        if (obj.numer == 0)
            out << "nan";
        else if (obj.numer < 0)
            out << "-inf";
        else
            out << "inf";
    }
    return out;
}


std::istream& operator>>(std::istream& in, Rational& obj)
{
    in >> obj.numer;

    char ch;
    in.get(ch); // Reads the next symbol (even if it's a space)

    if (ch == '/' || ch == '\\')
        in >> obj.denom;
    else
        obj.denom = 1;

    obj.simplify();
    return in;
}


Rational::operator double() const
{
    return numer / (double)denom;
}


Rational::operator float() const
{
    return numer / (float)denom;
}


void Rational::simplify()
{
    int gcd = std::abs(std::gcd(numer, denom));
    if (gcd != 0) {
        numer /= gcd;
        denom /= gcd;
    }
}


void Rational::fixNegation()
{
    if ((numer < 0 && denom < 0) || (numer > 0 && denom < 0)) {
        numer *= -1;
        denom *= -1;
    }
}
