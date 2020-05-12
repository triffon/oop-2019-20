#include <iostream>

using std::cout;
using std::endl;

class Base1 {

public:
    Base1() {
        a = 1;
        cout << "Base1()" << endl;
    }
    Base1(int _a) : a(_a) {
        cout << "Base1(_)" << endl;
    }
    ~Base1() {
        cout << "~Base1()" << endl;
    }
    void print() {
        cout << a << endl;
    }
    int a;

};

class Base2 {

public:
    Base2() {
        b = 2;
        cout << "Base2()" << endl;
    }
    Base2(int _b) : b(_b) {
        cout << "Base2(_)" << endl;
    }
    ~Base2() {
        cout << "~Base2()" << endl;
    }
    void print() {
        cout << b << endl;
    }
    int b;

};

class Der : public Base2, public Base1 {

public:
    Der() {
        c = 3;
        cout << "Der()" << endl;
    }
    Der(int _a, int _b, int _c) : Base1(_a), Base2(_b), c(_c) {
        cout << "Der(_)" << endl;
    }
    ~Der() {
        cout << "~Der()" << endl;
    }
    void print() {
        Base1::print();

        Base2::print();

        cout << c << endl;
    }
    int c;

};

int main() {
    Der d;
    d.a = 1;
    d.b = 2;
    d.c = 3;

    d.print();

    Der d1(7, 8, 9);
    d1.print();

    return 0;
}