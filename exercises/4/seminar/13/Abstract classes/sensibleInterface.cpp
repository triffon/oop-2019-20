#include <iostream>
using namespace std;

class Writable {
public:
    virtual void write(ostream& out) = 0;
};

class Readable {
public:
    virtual void read(istream& in) = 0;
};

class A: public Writable, public Readable {
public:
    virtual void write(ostream& out) {
        out<< "A";
    }

    virtual void read(istream& in) {}
};

class B: public Writable {
public:
    virtual void write(ostream& out) {
        out<< "B";
    }
};

void print(Writable& p) {
    cout<< "this object is ";
    p.write(cout);
    cout<< endl;
}

int main() {
    A a;
    print(a);

    B b;
    print(b);

    return 0;
}
