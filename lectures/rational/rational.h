struct Rational {
  long numer;
  unsigned long denom;

  Rational();

  Rational(long n, unsigned long d);

  long getNumerator()             { return numer; }
  unsigned long getDenominator()  { return denom; }

  void print();
  void printnl();
  double toDouble();

  void read();
};

Rational multiply(Rational p, Rational q);
Rational divide(Rational p, Rational q);
Rational add(Rational p, Rational q);
Rational subtract(Rational p, Rational q);