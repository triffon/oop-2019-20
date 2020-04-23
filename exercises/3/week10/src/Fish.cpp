#include "Fish.h"
// Initialize static member of class Box
int Fish::fishCount = 0;
Fish::Fish()
{
    fishCount++;
}

Fish::~Fish()
{
    fishCount--;
}
