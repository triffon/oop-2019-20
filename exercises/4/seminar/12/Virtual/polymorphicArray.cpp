#include <iostream>
using namespace std;

class B;

class A {
    int* x;

protected:
    void copyData(const A& other) {
        clearData();

        x = new int;
        *x = *other.x;
    }

    void clearData() {
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

    A& operator=(const A& other) {
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

    virtual void print() {
        cout<< "x is "<< *x;
    }

};


class B: public A {
    int* y;

    void copyData(const B& other) {
        clearData();

        A::copyData(other);
        y = new int;
        *y = *other.y;
    }

    void clearData() {
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
        delete y;
    }

    B* clone() {
        return new B(*this);
    }

    void print() {
        A::print();
        cout<< " y is "<< *y;
    }
};

int main () {
    A* arr[3];

    arr[0] = new B(6, 7);
    arr[1] = new A(5);
    arr[2] = new B(8, 9);

    delete arr[0];
    arr[0] = arr[1]->clone();

    for(int i = 0; i< 3; ++i) {
        arr[i]->print();
        cout<< endl;
    }

    for(int i = 0; i< 3; ++i) {
        delete arr[i];
    }

    return 0;
}
