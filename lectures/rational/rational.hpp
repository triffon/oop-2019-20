#ifndef __RATIONAL_HPP
#define __RATIONAL_HPP

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

  void read();
};

Rational multiply(Rational const& p, Rational const& q);
Rational divide(Rational const& p, Rational const& q);
Rational add(Rational const& p, Rational const& q);
Rational subtract(Rational const& p, Rational const& q);

#endif