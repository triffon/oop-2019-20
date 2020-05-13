#include <iostream>
using namespace std;

class A {
public:
    virtual void print() {
        cout<< "i'm a\n";
    }
};

class B: public A {
    virtual void print() {
        cout<< "i'm b\n";
    }
};

class C: public A {
    virtual void print() {
        cout<< "i'm c\n";
    }
};

int main () {
    B b;
    C c;

    A* p[] = { &b, &c };

    for(int i = 0; i< 2; ++i) {
        p[i]->print();
    }

    return 0;
}
