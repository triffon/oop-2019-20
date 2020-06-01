
#include <iostream>
using namespace std;

class Base1 {
public:
    void print() {
        cout<< "base 1";
    }
};

class Base2 {
public:
    void print() {
        cout<< "base 2";
    }
};

class Derived: public Base1, public Base2 {};

int main() {
    Derived d;
    d.print();
    //d.Base1::print();

    return 0;
}
