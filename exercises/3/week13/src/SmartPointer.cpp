#include "SmartPointer.h"
#include <iostream>

using namespace std;

SmartPointer::SmartPointer(int *p) {
    cout << "SmartPointer(int *p)" << endl;
    ptr = p;
}

SmartPointer::~SmartPointer() {
    cout << "~SmartPointer()" << endl;
    delete ptr;
}

int& SmartPointer::operator*() {
    cout << "operator*()" << endl;
    return *ptr;
}
