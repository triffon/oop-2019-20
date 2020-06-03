#include <iostream>
using namespace std;

class Base {
public:
    Base(int b): b(b) {
        //cout<< "constructing Base"<< endl;
    }
protected:
    int b;
};

class Mid1: virtual public Base {
public:
    Mid1(int b = 5): Base(b) {
        //cout<< "constructing Mid1"<< endl;
    }
    void print() {
        cout<< b<< endl;
    }
};

class Mid2: virtual public Base {
public:
    Mid2(int b = 6): Base(b) {
        //cout<< "constructing Mid2"<< endl;
    }
    void print() {
        cout<< b<< endl;
    }
};

class Derived: public Mid1, public Mid2 {
public:
    Derived(int b): Base(b) {
        //cout<< "constructing Derived"<< endl;
    }
    void print() {
        Mid1::print();
        Mid2::print();
    }
};

int main() {
    Derived d(4);
    d.print();

    return 0;
}
