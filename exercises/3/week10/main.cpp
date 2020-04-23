#include <iostream>
#include "Singleton.h"
#include "Fish.h"
using namespace std;
/// Those are functions and variables that are part of the class instead of a part of a specific instance.
/// Or we could look at it as something that is part of every instance.
/// The idea is that static members are shared between all the instances and can be accessed without even creating an instance.
void staticMemberDemo(){
    Fish f;
    /// Accessed using the class name and the scope resolution operator ::.
    cout << Fish::fishCount << endl;
    /// Alternatively could be accessed as a normal member of the class
    cout << f.fishCount << endl;
    cout << "===========================" << endl;
    Fish f2, f3;
    /// The value is shared across every object
    cout << "Fish::fishCount " <<  Fish::fishCount << endl;
    cout << "f.fishCount " << f.fishCount << endl;
    cout << "f2.fishCount " << f2.fishCount << endl;
    cout << "f3.fishCount " << f3.fishCount << endl;
}
/// Singleton design pattern demo
/// The idea is that this is a class which has one instance, no more
void singletonDemo(){
    /// new Singleton(); // Won't work
    Singleton* s = Singleton::getInstance();
    s->setData(12);
    Singleton* s2 = Singleton::getInstance();
    cout << s2->getData() << endl;
}

int main()
{
    /// staticMemberDemo();
    /// singletonDemo();
    return 0;
}
