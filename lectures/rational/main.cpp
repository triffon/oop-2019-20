#include <iostream>
#include <cmath>
#include <numeric>

struct Rational {
  long numer;
  unsigned long denom;

  Rational() {
      numer = 0;
      denom = 1;
  }

  Rational(long n, unsigned long d) {
      if (d == 0) {
          std::cerr << "Нулев знаменател, променям на 1" << std::endl;
          d = 1;
      }
      if (n == 0)
        d = 1;
      unsigned long g = std::gcd(std::abs(n), d);
      numer = n / g;
      denom = d / g;
  }

  long getNumerator()    { return numer; }
  unsigned long getDenominator()  { return denom; }

  void print() {
      // TODO: по желание да извежда q = преди числото
      std::cout << numer << '/' << denom;
  }

  void printnl() {
      print();
      std::cout << std::endl;
  }

  double toDouble() {
      return (double)numer / denom;
  }

  void read() {
      // 1/2
      std::cin >> numer;
      std::cin.get(); // прескачаме символа '/'
      std::cin >> denom;
      std::clog << "[LOG] numer = " << numer << std::endl;
      std::clog << "[LOG] denom = " << denom << std::endl;
  }
};

Rational multiply(Rational p, Rational q) {
    return Rational(p.getNumerator() * q.getNumerator(),
                    p.getDenominator() * q.getDenominator());
}

Rational divide(Rational p, Rational q) {
    return Rational(p.getNumerator() * q.getDenominator(),
                    p.getDenominator() * q.getNumerator());
}

Rational add(Rational p, Rational q) {
    return Rational(p.getNumerator() * q.getDenominator() +
                    q.getNumerator() * p.getDenominator(),
                    p.getDenominator() * q.getDenominator());
}

Rational subtract(Rational p, Rational q) {
    return Rational(p.getNumerator() * q.getDenominator() -
                    q.getNumerator() * p.getDenominator(),
                    p.getDenominator() * q.getDenominator());
}

unsigned fact(unsigned n) {
    unsigned product = 1;
    for(unsigned i = 2; i <= n; i++)
        product *= i;
    return product;
}

Rational ratexp(unsigned k, unsigned n) {
    Rational sum(0, 1);
    for(unsigned i = 0; i <= n; i++)
        // !!! sum += pow(k, i) / fact(i);
        // TODO: да се сметне общия член на редицата
        sum = add(sum, Rational(pow(k, i), fact(i)));
    return sum;
}

void testRationals() {
    // Rational r;
    Rational r(1, 2);
    Rational q = Rational(3, 4);
    q.printnl();
    r.printnl();
    q = r;
    q.printnl();
    std::cout << q.toDouble() << std::endl;
    q.read();
    q.printnl();
}

void testRatExp() {
    Rational r = ratexp(2, 14);
    r.printnl();
    std::cout << "r      = " << r.toDouble() << std::endl;
    std::cout << "exp(2) = " << exp(2) << std::endl;
}

int main(int, char**) {
    // testRationals();
    testRatExp();
}
