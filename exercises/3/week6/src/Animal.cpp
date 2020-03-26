#include "Animal.h"
#include <iostream>
using namespace std;
Animal::Animal(int age)
{
    this->age = age;
    cout << "Animal() is " << this->age << endl;
}
void Animal::sleep(){
    cout << "zzz" << endl;
}
Animal::~Animal()
{
    cout << "~Animal()" << endl;
}
