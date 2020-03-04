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
  Rational();

  Rational(long n, unsigned long d);

  long getNumerator() const            { return numer; }
  unsigned long getDenominator() const { return denom; }

  void print() const;
  void printnl() const;
  double toDouble() const;

  void read();
};

Rational multiply(Rational p, Rational q);
Rational divide(Rational p, Rational q);
Rational add(Rational p, Rational q);
Rational subtract(Rational p, Rational q);

#endif