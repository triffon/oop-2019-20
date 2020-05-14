#include <iostream>

using std::cout;
using std::endl;

class Base {

public:
    Base(int _a, int _b) : a(_a), b(_b) {}
    Base(Base const & b1) : a(b1.a), b(b1.b) {}
    void print() {
        cout << "base: " << a << " " << b << endl;
    }
    int a, b;

};

class Der : public Base {

public:
    Der(int _a, int _b, int _c, int _d) : Base(_a, _b), c(_c), d(_d) {}
    Der(Der const & d1) : Base(d1), c(d1.c), d(d1.d) {}
    void print() {
        Base::print();
        cout << "der: " << c << " " << d << endl;
    }
    int c, d;

};

int main() {
    Der d1(1, 2, 3, 4);
/* 
    d1.a = 1;
    d1.b = 2;
    d1.c = 3;
    d1.d = 4;
*/    
    d1.print();

    Der d2(d1);
    d1.a = 11;
    d1.print();
    d2.print();

    return 0;
}