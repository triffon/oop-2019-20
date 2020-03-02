#include <iostream>
using namespace std;

struct Number {
    int val;
};

Number operator+(const Number a, const Number b) {
    return Number {a.val - b.val};
}

int main () {
    Number x {7}, y {5};
    cout<< (x+y).val<< endl;

    return 0;
}
