#include <cmath>
#include "utility.hpp"

int utility::gcd(int a, int b) {
    a = abs(a);
    b = abs(b);

    if (b == 0) {
        return 1;
    }

    if (a < b) {
        return gcd(b, a);
    }

    if (a % b == 0) {
        return b;
    }

    return gcd(b, a % b);
}