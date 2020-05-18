#include <iostream>
using namespace std;

class A {
    public:
    virtual void print() = 0;
};

class B: public A {
    public:
    virtual void print() {
        cout<< "B"<< endl;
    }
};

class C: public A {
    public:
    virtual void print() {
        cout<< "C"<< endl;
    }
};

int main () {
    A* b = new B;
    b->print();
    delete b;

    return 0;
}
