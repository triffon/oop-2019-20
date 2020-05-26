#include <iostream>

using std::cout;
using std::endl;

class A {

public:
    A & operator[](int);
    void f1();
    int x;

};

A & A::operator[](int i) {
    x = 2 * i;
    return *this;
}

void A::f1() {
    (*this).operator[](12);
};

int main() {
    A a1;

    a1[11];
    a1.f1();
    cout << a1.x << endl;

    return 0;
}
