#include <iostream>
using namespace std;

class A {
    public:
    virtual void print() {
        cout<< "i'm A\n";
    }

    virtual void f() {}
};


class B: public A {
    public:
    void print() {
        cout<< "i'm B\n";
    }
};

class C: public A {
    public:
    void print() {
        cout<< "i'm C\n";
    }

    void f();
};

int main () {

    A a;
    //a.print();

    A* p = &a;
    p->print();
    //(*p).print();

    B b;
    b.print();

    cout<< "-----------------\n";

    //int x = 5;
    //double* px = &x;

    p = &b;
    p->print();
    //(*p).print();

    C c;
    //c.print();

    p = &c;
    p->print();

    p = new B; // heap
    p->print();
    delete p;
    p = NULL;

    return 0;
}
