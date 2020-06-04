#include <iostream>
#include "DynamicArray.h"
#include "Student.h"
using namespace std;

void func(int x = 5){
    cout << x;
}

int main()
{
    Faculty f("FMI");
    Faculty f2(f);
    f = f2;
    Student s(f,81712,3);
    DynamicArray d;
    for(int i=0;i<9;i++)
        d.append(1);
    cout << d[1] << endl;
    return 0;
}
