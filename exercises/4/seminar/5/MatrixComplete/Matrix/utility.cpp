#include "utility.hpp"
#include <iostream>
using namespace std;

int Utility::gcdHelper(int a, int b) {
    if (b == 0) {
        return 1;
    }

    if (a % b == 0) {
        return b;
    }

    return gcd(b, a % b);
}

int Utility::gcd(int a, int b) {
    a = abs(a);
    b = abs(b);

    if(a < b) {
        return gcd(b, a);
    }

    return gcdHelper(a, b);
}
