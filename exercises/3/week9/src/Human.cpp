#include "Human.h"
#include <iostream>
#include <cstring>
using namespace std;
/// order of instantiation is in the following order
/// Base class, member data(initialization list or default value in header), constructor of current object
/// Here we tell the program to call the Animal(int) constructor with age as argument
Human::Human(char * name, int age):Animal(age)
{
    cout << "Human::Human()" << endl;
    setName(name);
}
void Human::setName(const char * name){
    if(name!=nullptr){
        delete[] this->name;
        this->name = new char[strlen(name)];
        strcpy(this->name, name);
    }
}
void Human::wakeUp(){
    /// We can call functions from our parents
    /// Pretty useful if you want to add functionality to a function without rewriting it
    Animal::wakeUp();
    cout << "Went to work" << endl;
}
char * Human::getName()const{
    return name;
}
/// Order of destruction is in reverse of construction which means that we first call this destructor and after that the destructor of our parents
Human::~Human()
{
    cout << "Human::~Human()" << endl;
}
