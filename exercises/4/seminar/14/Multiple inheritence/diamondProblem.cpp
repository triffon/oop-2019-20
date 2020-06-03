#include <iostream>
using namespace std;

class Base {
public:
    Base(int b): b(b) {}
protected:
    int b;
};

class Mid1: public Base {
public:
    Mid1(int b): Base(b) {}
    void print() {
        cout<< b<< endl;
    }
};

class Mid2: public Base {
public:
    Mid2(int b): Base(b) {}
    void print() {
        cout<< b<< endl;
    }
};

class Derived: public Mid1, public Mid2 {
public:
    Derived(int b1, int b2): Mid1(b1), Mid2(b2) {}
    void print() {
        Mid1::print();
        Mid2::print();
    }
};

int main() {
    Derived d(5,6);
    d.print();

    return 0;
}
