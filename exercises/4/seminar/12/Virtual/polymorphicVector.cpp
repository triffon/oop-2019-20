#include <iostream>
#include "vector.h"
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

    virtual void print() const {
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

    void print() const {
        A::print();
        cout<< " y is "<< *y;
    }
};

class AArray {
private:
    Vector<A*> data;

    void copyData(const AArray& other) {
        clearData();

        for(int i = 0; i< data.getSize(); ++i) {
            delete data[i];
            data[i] = other.data[i]->clone();
        }
    }

    void clearData() {
        for(int i = 0; i< data.getSize(); ++i) {
            delete data[i];
        }
    }
public:
    AArray() {}

    AArray(const AArray& other) {
        copyData(other);
    }

    AArray& operator=(const AArray& other) {
        if(this == &other) {
            return *this;
        }

        copyData(other);
        return *this;
    }

    ~AArray() {
        clearData();
    }

    void append(A newElement) {
        data.append(newElement);
    }

    int getSize() {
        return data.getSize();
    }

    const A* operator[](int index) {
        return data[index];
    }
};

int main () {
    AArray arr;

    arr.append(new B(6, 7));
    arr.append(new A(5));
    arr.append(new B(8, 9));

    for(int i = 0; i< 3; ++i) {
        arr[i]->print();
        cout<< endl;
    }

    return 0;
}
