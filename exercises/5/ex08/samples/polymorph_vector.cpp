#include <iostream>
#include <cstring>

#include "vector.cpp"

using std::cout;
using std::endl;

/*
    Vector<T>   Object (print, ++)
        |       /   |    |      \
       PolyVector  Int  Double  Char
*/

// Object
class Object {

public:
    virtual void print() const = 0;

};

// Int
class Int : public Object {

public:
    Int(int);
    void print() const;

private:
    int x;

};

Int::Int(int _x) : x(_x) {}

void Int::print() const {
    cout << x << endl;
}

// Double
class Double : public Object {

public:
    Double(double);
    void print() const;

private:
    double x;

};

Double::Double(double _x) : x(_x) {}

void Double::print() const {
    cout << x << endl;
}

// Char
class Char : public Object {

public:
    Char(char);
    void print() const;

private:
    char x;

};

Char::Char(char _x) : x(_x) {}

void Char::print() const {
    cout << x << endl;
}

//typedef Vector<Object *> PolyVector;

// PolyVector
class PolyVector : public Vector<void *>, public Object {

public:
    void print() const;

};

void PolyVector::print() const {
    for (int i = 0; i < size(); ++i) {
        Object * ptr;
        // TODO:
        // ptr = (Object *)(get(i));
        // ptr->print();
        cout << i << " ";
    }
}

// Main
int main() {
    /*
    Vector<int> vi;
    vi.push(10);
    vi.push(11);
    vi.push(12);

    for (int i = 0; i < vi.size(); ++i) {
        cout << vi[i] << endl;
    }
    */

    /*
    Vector<Object *> vo;
    vo.push(new Int(10));
    vo.push(new Char('z'));
    vo.push(new Double(2.5));

    for (int i = 0; i < vo.size(); ++i) {
        vo[i]->print();
    }
    */

    PolyVector vo;
    vo.push(new Int(10));
    vo.push(new Char('z'));
    vo.push(new Double(2.5));

    for (int i = 0; i < vo.size(); ++i) {
        ((Object *)vo[i])->print();
    }

    vo.print();

    return 0;
}
