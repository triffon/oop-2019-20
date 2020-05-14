#include "Human.h"
#include <iostream>
using namespace std;
Human::Human(int age):Animal(age)
{
    cout << "Human() is " << this->age << " years old" << endl;

}
void Human::sleep(){
    cout << "Going under the blankets in the bed" << endl;
}
void Human::walk(){
    cout << "A walk in the park" << endl; /// Haha not today :( stupid covid
}
Human::~Human()
{
    cout << "~Human()" << endl;
}
