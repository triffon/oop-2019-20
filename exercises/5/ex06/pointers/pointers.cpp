#include <iostream>

using std::cout;
using std::endl;

int x;
int * px;

class A {

public:
    double a;
    void p();
    void f(int);

private:
    double b;

};

void A::p() {
    cout << "a = " << a << endl;
}

void A::f(int x) {
    cout << "f(" << x << ")" << endl;
    a = x;
}

int main() {
    x = 10;

    cout << x << endl;

    px = &x;
    *px = 12;

    cout << px << ' ' << (*px) << ' ' << x << endl;

    A object;

    double A::*pa = &A::a;

    object.*pa = 99;
    cout << object.*pa << endl;

    A anotherObject;
    anotherObject.a = 12;
    cout << anotherObject.*pa << endl;

    // does not work with private variables
    // pa = &A::b;

    object.p();

    void (A::*pp)() = &A::p;

    (object.*pp)();

    
    void (A::*pf)(int) = &A::f;

    (object.*pf)(9);
    object.p();

    anotherObject.p();


    return 0;
}