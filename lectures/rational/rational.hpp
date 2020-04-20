#ifndef __RATIONAL_HPP
#define __RATIONAL_HPP

#include <iostream>

class Rational;
class Rational;
class Rational;
class Rational;
class Rational;
class Rational;

class Rational {
  long numer;
  unsigned long denom;
public:
//  Rational();

  Rational(long n = 0, unsigned long d = 1);

  Rational(Rational const&);

  long getNumerator() const            { return numer; }
  unsigned long getDenominator() const { return denom; }

  void print() const;
  void printnl() const;
  double toDouble() const;

  friend std::ostream& operator<<(std::ostream&, Rational const&); /* { ... } */
  friend std::istream& operator>>(std::istream&, Rational&);

  bool operator==(Rational const&) const;

  void read();
};

Rational multiply(Rational const& p, Rational const& q);
Rational divide(Rational const& p, Rational const& q);
Rational add(Rational const& p, Rational const& q);
Rational subtract(Rational const& p, Rational const& q);

std::ostream& operator<<(std::ostream&, Rational const&);
std::istream& operator>>(std::istream&, Rational&);

#endif