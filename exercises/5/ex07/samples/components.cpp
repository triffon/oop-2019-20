#include <iostream>

class Base {

public:
    void f1(int x) {
        bx = x;
    }
    void print() const {
        std::cout << "Base.bx = " << bx << std::endl; 
    }

protected:
    int bx;

};

class Der : public Base {

public:
    void f1(int x) {
        bx = x;
        Base::bx = 2 * x;
    }
    void print() const {
        Base::print();
        std::cout << "Der.bx = " << bx << std::endl; 
    }

protected:
    int bx;

};

int main() {
    Base b1;
    b1.f1(10);
    b1.print();

    Der d1;
    d1.f1(15);
    d1.print();
    //d1.Base::f1(11);
    //d1.Base::print();
    return 0;
}