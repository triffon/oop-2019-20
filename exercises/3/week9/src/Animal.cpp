#include "Animal.h"
#include <iostream>
using namespace std;
Animal::Animal(int age)
{
    setAge(age);
    cout << "Animal::Animal()" << endl;
}

void Animal::wakeUp(){
    cout << "Woke up and had a breakfast" << endl;
}
int  Animal::getAge()const{
    return age;
}
void Animal::setAge(int age){
    this->age = age;
}
Animal * Animal::clone(){
    return new Animal(*this);
};
Animal::~Animal()
{
    cout << "Animal::~Animal()" << endl;
}
