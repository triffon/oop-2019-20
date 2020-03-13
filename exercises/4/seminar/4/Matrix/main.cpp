#include <iostream>
#include "ration.hpp"
#include "matrix.hpp"
using namespace std;

int main () {
    Rational r1(5, 2), r2(1, 1);
    Rational r3, r4;

    Rational data[2][2];
    data[0][0] = r1;
    data[0][1] = r2;
    data[1][0] = r3;
    data[1][1] = r4;

    Matrix m1(data, 2, 2);

    cout<< r3.getA()<< " "<< r3.getB()<< endl;

    return 0;
}
