#include <iostream>
using namespace std;

void add5AndPrint(int& x) {
    x += 5;
    cout<< x<< endl;
}

void add5AndPrint(int&& x) {
    x += 5;
    cout<< x<< endl;
}

void print(const int& x) {
    cout<< x<< endl;
}

int main() {

    int x;

    // lvalue is a result of an expression that has a semi-permanent address in memory
    4+5;
    x = 4+5;

    add5AndPrint(4+5);
    add5AndPrint(x);

    print(4+5);
    print(x);

    int&& y = 4+5;
    y += 4;
    cout<< y<< endl;

    int&& z = 5;

    z += 6;

    cout<< z;

    return 0;
}
