#include <iostream>
#include "Human.h"
#include "Centaur.h"
using namespace std;

/// Simple inheritance demo(data is inherited)
/// access modifiers in the different types of inheritance
/// Order of construction and destruction of objects
/// virtual functions
/// Interfaces and abstract classes
/// call base class function when overriding
void simpleInheritanceDemo(){
    Human h("Pesho",21);
    Animal a(12);
    cout << a.getAge() << endl;
    /// Even though getAge isn't defined in Human, we "inherit" it from Animal
    cout << h.getAge() << endl;
}
void polymorphismDemo(){
    Human h("Pesho",21);
    Animal temp = h;
    Animal a(12);
    /// static polymorphism, it calls just the function for the specified class
    /// in other word it just looks on what object type you are calling it
    a.wakeUp();
    temp.wakeUp();
    cout << "===================" << endl;
    Animal * ptr = &a;
    Animal * ptr2 = &h;
    /// Dynamic polymorphism , when invoking virtual functions it calls the appropriate for the instantiated type
    /// the other functions(non virtual) are still checked statically(the ones in Animal)
    ptr->wakeUp();
    cout << "-----------" << endl;
    ptr2->wakeUp();
    /// Virtual destructors are used to call the appropriate desctructor
    Animal * a2 = new Human();
    delete a2;
    cout << "+++++++++++++++++++" << endl;
}
void virtualInheritanceDemo(){
    Centaur c;
    /// getAge and setAge appear only once(in Animal) so there is no ambiguity
    c.setAge(12);
    cout << c.getAge() << endl;

    c.wakeUp();
}
void virtualInheritanceArrayDemo(){
    Animal ** arr = new Animal * [3];
    arr[0] = new Human();
    arr[1] = new Animal();
    arr[2] = new Horse();
    delete arr[2];
    arr[2] = arr[1]->clone();
}

int main()
{
    /// simpleInheritanceDemo();
    /// polymorphismDemo();
    /// virtualInheritanceDemo();
    /// virtualInheritanceArrayDemo();
    return 0;
}
