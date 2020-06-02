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
    virtual void print() = 0;
    virtual Object & operator++() = 0;

};

// Int
class Int : public Object {

public:
    Int(int);
    void print();
    Int & operator++();
    Int operator++(int);

private:
    int x;

};

Int::Int(int _x) : x(_x) {}

void Int::print() {
    cout << x << endl;
}

Int & Int::operator++() {
    ++x;
    return *this;
}

Int Int::operator++(int) {
    Int ret(*this);

    ++x;

    return ret;
}

// Double
class Double : public Object {

public:
    Double(double);
    void print();
    Double & operator++();

private:
    double x;

};

Double::Double(double _x) : x(_x) {
    ++x;
}

void Double::print() {
    cout << x << endl;
}

Double & Double::operator++() {}

// Char
class Char : public Object {

public:
    Char(char);
    void print();
    Char & operator++();

private:
    char x;

};

Char::Char(char _x) : x(_x) {
    ++x;
}

void Char::print() {
    cout << x << endl;
}

Char & Char::operator++() {}

//typedef Vector<Object *> PolyVector;

// PolyVector
class PolyVector : public Vector<void *>, public Object {

public:
    void print();
    PolyVector & operator++();

};

void PolyVector::print() {
    for (int i = 0; i < size(); ++i) {
        Object * ptr;
        //ptr = (Object *)(get(i));
        ptr = (Object *)((*this)[i]);
        ptr->print();
    }
}

PolyVector & PolyVector::operator++() {
    // TODO: increment all data in vector
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

    Int i1(10);
    i1.print();
    ++i1;
    i1.print();
    i1++;
    i1.print();
    (i1++).print();
    (++i1).print();

    return 0;
}
