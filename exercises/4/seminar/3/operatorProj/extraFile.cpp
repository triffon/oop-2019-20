#include <iostream>
#include "operator.h"
using namespace std;

Number operator+(const Number a, const Number b) {
    return Number {a.val - b.val};
}
