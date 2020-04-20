#include "Horse.h"
#include <iostream>
using namespace std;
Horse::Horse()
{
    cout << "Horse::Horse()" << endl;
}
void Horse::wakeUp(){
    Animal::wakeUp();
    cout << "Running in the linear field" << endl;
}
Horse::~Horse()
{
    cout << "Horse::~Horse()" << endl;
}
