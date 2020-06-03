#include "Student.h"
#include <iostream>
using namespace std;

Student::Student(Faculty f, int fNum2, int x):fNum(fNum2),f(f),x(x)
{
    cout << "Student" << endl;
    x++;
}
int Student::getfNum(){
    return fNum;
}
const char * Student::getFacultyName()const{
    return f.getName();
}
int Student::getX(){
    return x;
}
Student::~Student()
{
    //dtor
}
