#include <iostream>

using namespace std;

class Base
{
public:
  virtual void print()
  {
    cout << "base" << endl;
  }
};

class Derived1 : public Base
{
public:
  void print()
  {
    cout << "base" << endl;
  }
};

class Derived2 : public Base
{
public:
  void print()
  {
    cout << "base" << endl;
  }
};

int main()
{
  Base* ptr1 = new Derived1;
  Base* ptr2 = new Derived2;

  // if ptr1 is pointer of Derived1 it will be successfully cast
  // else d1 will hold nullptr value
  Derived1* d1 = dynamic_cast<Derived1*>(ptr1); // this will pass
  if (d1 == nullptr) {
    cout << "ptr1 is not pointing to Derived1" << endl;
  }

  Derived1* d2 = dynamic_cast<Derived1*>(ptr2); // this won't pass
  if (d2 == nullptr) {
    cout << "ptr2 is not pointing to Derived1*" << endl;
  }

  return 0;
}