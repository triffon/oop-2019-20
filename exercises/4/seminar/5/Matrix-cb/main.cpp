#include <iostream>
#include "rational.hpp"
#include "matrix.hpp"
using namespace std;

int main () {
    Rational r1(5, 2), r2(1, 1), r3(6, 8), r4(5, 6);
    Rational data[4] = {r1, r2, r3, r4};

    (r1 + r4).print();
    cout<< endl;

    Matrix m1(data, 2, 2);
    m1.print();

    return 0;
}
