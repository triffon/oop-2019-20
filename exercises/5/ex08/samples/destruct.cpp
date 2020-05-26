#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

class A {

public:
    A(const char * = "");
    virtual ~A();
    void print() const;

private:
    char * a;

};

A::A(const char * _a) {
    cout << "A()" << endl;
    a = new char[strlen(_a) + 1];
    strcpy(a, _a);
}

A::~A() {
    cout << "~A()" << endl;
    delete[] a;
}

void A::print() const {
    cout << "A::print() -> " << a << endl;
}

class B : virtual public A {

public:
    B(const char * = "", const char * = "");
    ~B();
    void print() const;

private:
    char * b;

};

B::B(const char * _a, const char * _b) : A(_a) {
    cout << "B()" << endl;
    b = new char[strlen(_b) + 1];
    strcpy(b, _b);
}

B::~B() {
    cout << "~B()" << endl;
    delete[] b;
}

void B::print() const {
    A::print();
    cout << "B::print() -> " << b << endl;
}

int main() {
    //A a1, a2("Ivan");

    //a1.print();
    //cout << endl;

    //a2.print();
    //cout << endl;

    //B b1, b2("Ivan", "Gosho");
    //B b2("Ivan", "Gosho");
    //b1.print();
    //b2.print();

    A * pa;
    pa = new B("Ivan", "Gosho");
    pa->print();
    //((B *)pa)->print();

    delete pa;

    return 0;
}