#include <iostream>

void f() {
    int a = 0;
    ++a;
    // ++a; a++
    static int b = 0;
    ++b;

    std::cout << a << ' ' << b << std::endl;
}

class A {

public:
    A();
    static int a;
    static int getB();

private:
    static int b;
    int c;

};

A::A() { }
int A::getB() {
    return b;
}

int A::a = 0;
int A::b = 0;

int main() {
    f();
    f();
    
    A p;
    p.a = 10;
    std::cout << p.a << std::endl;

    A q;
    std::cout << q.a << std::endl;

    std::cout << A::a << std::endl;

    std::cout << A::getB() << std::endl;

    return 0;
}