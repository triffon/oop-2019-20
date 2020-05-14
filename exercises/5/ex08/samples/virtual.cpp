#include <iostream>

using std::cout;
using std::endl;

class Base1 {

public:
    Base1() {
        a = 1;
        cout << "Base1()" << endl;
    }
    Base1(int _a) : a(_a) {
        cout << "Base1(_)" << endl;
    }
    ~Base1() {
        cout << "~Base1()" << endl;
    }
    void print() {
        cout << a << endl;
    }
    int a;

};

class Der1 : virtual public Base1 {

public:
    void print1() {
        cout << a << endl;
    }

};

class Der2 : virtual public Base1 {

public:
    void print2() {
        cout << a << endl;
    }

};

class Der : public Der1, public Der2 {

public:
    void print() {
        print1();
        print2();
    }

}; 

/*
        Base1
        /   \
     Der1   Der2
        \   /
         Der
*/

/*
  Base1       Base1
     \        /
     Der1   Der2
        \   /
         Der
*/
int main() {
    Der d;
    d.Der1::a = 10;
    d.Der2::a = 12;

    d.print();

    Der2 d2;
    d2.a = 13;
    d2.print();

    return 0;
}