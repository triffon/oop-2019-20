#include <iostream>

int gcd(int a, int b) {
    if (a == b) return a;
    if (a > b) return gcd(a - b, b);
    return gcd(a, b - a);
}

struct rational {
    int nom;
    int denom;
};

rational makeRat(int _a, int _b) {
    int g = gcd(_a, _b);
    rational rat = {_a / g, _b / g};
    return rat;
};

rational add(rational const & p, rational const & q) {
    return makeRat(p.nom * q.denom + q.nom * p.denom, p.denom * q.denom);
}

rational substract(rational const & p, rational const & q) {
    return makeRat(p.nom * q.denom - q.nom * p.denom, p.denom * q.denom);
}

rational multiply(rational const & p, rational const & q) {
    return makeRat(p.nom * q.nom, p.denom * q.denom);
}

rational divide(rational const & p, rational const & q) {
    return makeRat(p.nom * q.denom, p.denom * q.nom);
}

int main() {
    rational p = makeRat(10, 15);

    std::cout << p.nom << '/' << p.denom << std::endl;

    rational q = makeRat(1, 2);

    rational s1 = add(p, q);
    std::cout << s1.nom << '/' << s1.denom << std::endl;

    rational s2 = substract(p, q);
    std::cout << s2.nom << '/' << s2.denom << std::endl;

    rational s3 = multiply(p, q);
    std::cout << s3.nom << '/' << s3.denom << std::endl;

    rational s4 = divide(p, q);
    std::cout << s4.nom << '/' << s4.denom << std::endl;

    return 0;
}
