#include "Faculty.h"
#include <cstring>
#include <iostream>
using namespace std;
///Unfortunately, in C++03, you cannot initialize arrays in initializer lists.
///You can in C++11 though if your compiler is newer :)
Faculty::Faculty(){
    cout << "Faculty()" << endl;
}
Faculty::Faculty(char * name)
{
    strcpy(this->name,name);
    cout << "Faculty(char * name) " << endl;
}
Faculty::Faculty(const Faculty& other){
        cout << this->name << " Faculty(const Faculty& other) " << other.name << endl;
        strcpy(this->name,other.name);
};
Faculty& Faculty::operator=(const Faculty& other){
    cout << this->name << " operator=(const Faculty& other) " << other.name << endl;
    strcpy(this->name,other.name);
    return *this;
}
const char * Faculty::getName()const{
    cout << "Faculty::getName()" << endl;
    return name;
}
Faculty::~Faculty()
{
    //dtor
}
