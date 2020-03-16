#include "utility.hpp"
#include <iostream>
using namespace std;

int Utility::gcd(int a, int b) {
    if(b == 0) {
        return 1;
    }

    if(a < b) {
        return gcd(b, a);
    }

    if(a%b == 0) {
        return b;
    }

    return gcd(b, a%b);
}
