#include <iostream>

using std::cout;
using std::endl;

class Base1 {

};

template <typename T>
class Der1 : public Base1 {

};

// ---------

template <typename T>
class Base2 {

};

class Der2 : public Base2<int> {

};

// -----------

template <typename T>
class Base3 {

public:
    Base3(T _a) : a(_a) {}
    T a;

};

template <typename T>
class Der3 : public Base3<T> {

public:
    Der3(T _a, T _b) : Base3<T>(_a), b(_b) {}
    T b;

};

int main() {
    Der1<int> d1;

    Der2 d2;

    Der3<int> d3(1, 2);
    cout << d3.a << " " << d3.b << endl;
    return 0;
}