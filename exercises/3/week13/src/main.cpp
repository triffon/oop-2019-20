#include <iostream>
#include <set>
#include <vector>
#include "SmartPointer.h"
#include "Student.h"
#include "StudentContainer.h"
#include "DynamicArray.h"
#include "Human.h"
#include "Bird.h"
using namespace std;
///You can call it with a string as argument because of implicit conversion
void implicitConverstionFunc(Student s){
    cout << s.getName() << endl;
}
void acceptInt(int n){};
void acceptString(char * s){};
void implicitConversionsDemo(){
    /// C++ allows implicit conversion from one type to another
    /// There are standard conversion such as type promotion
    short b;
    acceptInt(b);
    /// User defined conversions also exist
    /// One expression e  of type T1 can be used in place of some type T2 if the user has defined:
    /// 1. non-explicit single-argument constructor
    /// T2 t = e;
    implicitConverstionFunc("Pesho");
    /// 2. non-explicit conversion member function operator T2()const (cast)
    Student s("Pesho",12345);
    acceptString(s);
    /// What about the keyword explicit in front of constructors in C++?
    /// it disallows the compiler to use these constructors for implicit conversions
}

///Example for a template function from previous time
///This doesn't create a real function rather a blueprint for creating more functions
template<class T, class N>
void templateFunction(T t, N n)
{
    std::cout << t << " " << sizeof(n) << '\n';
}

/// Template specialization, used to make a template function only for the specified template parameters
template<>
void templateFunction<int,int>(int a,int b){
    std::cout << "I see you gave me two ints" << endl;
}

/// Explicit instantiation, this creates a real function from the template
/// You don't really need to do this, there is implicit instantiation
//template void templateFunction<Student,int>(Student,int);

void templateFunctionsDemo(){
    Student kamen("Kamen",81712);
    ///explicitly stating template parameters to be Student and int
    templateFunction<Student,int>(kamen,12);
    /// same as above, template parameter deduction
    templateFunction(kamen,12);
    /// the function below will call the one with template specialization
    templateFunction<int,int>(123,123);
}

void templateClassesDemo(){
    DynamicArray<int> d;
    d.append(1998);
    cout << d[0] << endl;

    DynamicArray<Student> group3;
    group3.append(Student("Niki",123456));
    group3.append(Student("Lucho",654321));
    cout << group3[0] << group3[1] << endl;
}
/// Inheritance allows us to makes classes
/// that inherit functions from other classes
/// and define new functions thus reusing code
void acceptAnimal(Animal* a){
    a->sleep();
}
void simpleInheritanceDemo(){
    Human h(21);
    Bird b(3);

    /// The new functions
    //b.fly();
    //h.walk();

    acceptAnimal(&b);
    acceptAnimal(&h);
}
void iteratorDemo(){
    vector<int> a;
    a.push_back(2);
    a.push_back(3);
    set<pair<int,char>> set2;
    set<int> s;
    s.insert(3);
    s.insert(69);
    cout << "=============" << endl;
    for(int i : s){
        cout << i << endl;
    }
    cout << "=============" << endl;
    set<int>::iterator it2 = s.begin();
    vector<int>::iterator it = a.begin();
    it2++;
    it++; 
    cout << *it << endl;
    cout << *it2 << endl;;
}
void customIteratorDemo(){
    DynamicArray<int> d;
    d.append(15);
    Iterator<int>* it = d.begin();

    cout << it->getCurrent() << endl;
}
void assertDemo(){
    assert(0==0);
}
int main()
{
    //templateFunctionsDemo();
    //templateClassesDemo();
    //implicitConversionsDemo();
    //simpleInheritanceDemo();
    iteratorDemo();
    //customIteratorDemo();
    return 0;
}
