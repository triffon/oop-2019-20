#include <iostream>
#include "SmartPointer.h"
#include "Student.h"
using namespace std;

///Use smart Pointers for creating dynamically allocated objects which delete themselves
void smartPtrDemo(){
    SmartPointer p(new int());
    *p = 15;
    cout << "SmartPointer Value is: " << *p << endl;
    int * p2 = new int(3);
    *p = *p2;
    cout << "SmartPointer Value is: " << *p << endl;
} ///Smart Pointer self deletes upon getting out of scope

///Const casts are a bad practice, avoid them if possible!
void constCastDemo(){
    int * a;
    const int * const b = new int(5);
    /* The statement below will assign a the value b thus allowing us to change it because a isn't constant even tho b is constant */
    a = const_cast <int *> (b);
    (*a)++;
    cout << *b << endl;

    /*The statement below will cause an error */
    //a = b;

    delete b;
}

void studentDemo(){
    Student s;
    cin >> s;
    Student s2 = s; ///just to test operator=
    cout << s2;
}
enum struct Test {test1, test2};
enum class Enum {test1, test2};
enum DaysOfWeek: char { MON='M', TUE='T', WED='W', THU='t', FRI='F', SAT, SUN};
enum Gender: bool {male=true, female=false};

void func(Test t){
    cout << (int)t << endl;
}

template<class T, class N>
void f(T t1, T t2, T t3, N n)
{
    std::cout << t1 << t2 << t3 << " " << sizeof(n) << '\n';
}

int main()
{
    Student kamen("Kamen",81712);

    f<Student,int>(kamen,kamen,kamen,12);

    func(Test::test1);
    cout << (int)Test::test1 << endl;
    return 0;
}
