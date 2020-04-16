#include "Centaur.h"
#include <iostream>
using namespace std;
/// Every class is responsible for the instantiation of its parents and virtually inherited classes
/// their parents don't instiate the virtual classes
Centaur::Centaur():Horse(),Human(),Animal()
{
    cout << "Centaur::Centaur()" << endl;
}
void Centaur::wakeUp(){
    /// We still have multiple wakeUps in the parents tho
    Human::wakeUp();
    Horse::wakeUp();
};
/// Animal destructor is called only once
Centaur::~Centaur()
{
    cout << "Centaur::~Centaur()" << endl;
}
