#include "Fish.h"
#include <iostream>
using namespace std;
/// Initialize static member of class Fish
int Fish::fishCount = 0;
Fish::Fish()
{
    fishCount++;
}
void Fish::func(){
    /// doesn't work, only static functions and members can be used in static functions
    /// nonStaticField++;
    cout << fishCount << endl;
}
Fish::~Fish()
{
    fishCount--;
}
