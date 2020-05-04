#include <iostream>

using namespace std;

class Base {

public:
  int a;
  Base(int a): a(a) {}
  Base() {}

  virtual void print() {
      cout << "Base Hi" << endl;
  }
  virtual Base* copy() {
    Base* n = new Base(*this);
    return n;
  }; 
};

class Derived : public Base {
  public:
    Derived(int a): Base(a) {}
    Derived() {}
    void print() {
      cout << "Derived Hi" << endl;
    }

    Base* copy() {
      Derived* n = new Derived(*this);
      return n;
    }
};

class Arr {
public:
  Base** arr;
  int count;
  Arr(): count(0) {
    arr = new Base*[4];
  }

  void add(Base* other) {
    arr[count] = other->copy();
    count++;
  }
};

int main() {
  Derived d1(4);
  Derived d2(4);
  Derived d3(4);
  Base bs;
  
  Arr a;
  a.add(&d1);
  a.add(&bs);
  a.arr[0]->print();
  a.arr[1]->print();

  return 0;
}