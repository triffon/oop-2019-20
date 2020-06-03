#include <iostream>
using namespace std;

class A {
public:
    virtual ~A() {}
};

class B: public A {
    int b;
public:
    B(int b = 3): b(b) {}

    void printB() {
        cout<< b<< endl;
    }
};

class C: public A {
    double c;
public:
    C(int c): c(c) {}
    void printC() {
        cout<< c<< endl;
    }
};

int main() {
    A* pA = new B;

    A* pA1 = new A;
    static_cast<B*>(pA1)->printB();
    delete pA1;

    B* pB = dynamic_cast<B*>(pA);
    if(pB != NULL) {
        pB->printB();

        //CB* pAA = static_cast<B*>(pB);

        //C* pC = static_cast<C*>(pB);
        //C* pC = (C*)(pB); //~ C* pC = reinterpret_cast<C*>(pB);
    }

    C* pC = dynamic_cast<C*>(pA);
    if(pC != NULL) {
        cout<< "this shouldn't show"<< endl;
    }

    delete pA;

    return 0;
}
