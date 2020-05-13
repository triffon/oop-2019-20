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
    Der(Base const & b1) : Base(b1), c(-1), d(-1) {}
    void print() {
        Base::print();
        cout << "der: " << c << " " << d << endl;
    }
    int c, d;

};

int main() {
 //   Der d1(1, 2, 3, 4);
/* 
    d1.a = 1;
    d1.b = 2;
    d1.c = 3;
    d1.d = 4;
*/    
 /*   d1.print();

    Der d2(d1);
    d1.a = 11;
    d1.print();
    d2.print();

    Der & pd1  = d1;
    Base & pb1 = d1;
    cout << "pd1.print" << endl;
    pd1.print();
    cout << "pb1.print" << endl;
    pb1.print();

    Der * pd2  = &d1;
    Base * pb2 = &d1;
    cout << "pd2.print" << endl;
    pd2->print();
    cout << "pb2.print" << endl;
    (*pb2).print();
*/
    Base x(0, 1);
    Der x2 = (Der) x;
    x2.print();

    Base * px = &x;
    Der * pdx = (Der *) px;

    (*pdx).print();
    cout << pdx->d << endl; 
    pdx->d = 10;
    (*pdx).print();
    //d1.print();
    //d2.print();

    return 0;
}