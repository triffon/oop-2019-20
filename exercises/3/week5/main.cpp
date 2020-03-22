#include <iostream>
#include "SmartPointer.h"
#include "Student.h"
using namespace std;

///Use smart Pointers for creating dynamically allocated objects which delete themselves
void smartPtrDemo(){
    SmartPointer p(new int());
    *p = 15;
    cout << "SmartPointer Value is: " << *p << endl;
    int *p2 = new int(3);
    *p = *p2;
    cout << "SmartPointer Value is: " << *p << endl;
} ///Smart Pointer self deletes upon getting out of scope

///Const casts are a bad practice, avoid them if possible!
void constCastDemo(){
    int * a;
    const int * const b = new int(5);
    /* The statement below will assign a the value b thus allowing us to change it because a isn't constant even tho b is constant
    a = const_cast <int *> (b);
    *a++;
    cout << *a << endl;*/

    /*The statement below will cause an error
    a = b;*/
}

void studentDemo(){
    Student s;
    cin >> s;
    Student s2 = s; ///just to test operator=
    cout << s2;
}
int main()
{
    smartPtrDemo();
    return 0;
}
