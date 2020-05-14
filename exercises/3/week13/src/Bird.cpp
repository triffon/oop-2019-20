#include "Bird.h"
#include <iostream>
using namespace std;
Bird::Bird(int age):Animal(age)
{
    cout << "Bird() is " << this->age << " years old"<< endl;
}
void Bird::sleep(){
    cout << "Laying in the nest with the other birds" << endl;
}
void Bird::fly(){
    cout << "A bird is flying" << endl;
}
Bird::~Bird()
{
    cout << "~Bird()" << endl;
}
