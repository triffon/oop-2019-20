#include <iostream>
using namespace std;

class B;

class A {
    int* x;

protected:
    void copyData(const A& other) {
        clearData();

        cout<< "copying x\n";
        x = new int;
        *x = *other.x;
    }

    void clearData() {
        cout<< "deleting x\n";
        delete x;
    }
public:
    A(int val = 5) {
        x = new int;
        *x = val;
    }

    A(const A& other): x(NULL) {
        copyData(other);
    }

    virtual A& operator=(const A& other) {
        if(this == &other) {
            return *this;
        }

        copyData(other);
        return *this;
    }

    virtual ~A() {
        clearData();
    }

    //virtual B& operator=(const B&) = 0;

    virtual A* clone() {
        return new A(*this);
    }

};


class B: public A {
    int* y;

    void copyData(const B& other) {
        clearData();

        A::copyData(other);
        cout<< "copying y\n";
        y = new int;
        *y = *other.y;
    }

    void clearData() {
        cout<< "deleting y\n";
        delete y;
    }
public:
    B(int x = 5, int y = 6): A(x) {
        this->y = new int;
        *(this->y) = y;
    }

    B(const B& other): y(NULL) {
        copyData(other);
    }

    B& operator=(const B& other) {
        if(this == &other) {
            return *this;
        }

        copyData(other);
        return *this;
    }

    ~B() {
        cout<< "deleting y\n";
        delete y;
    }

    B* clone() {
        return new B(*this);
    }
};

int main () {

    //A a;
    //B b;
    //A* p = &b;

    A* p = new B;

    B b1(6, 7);
    *p = b1.clone();

    delete p;
    p = NULL;

    return 0;
}
