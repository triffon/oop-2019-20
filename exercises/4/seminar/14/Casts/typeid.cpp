#include <iostream>
#include <typeinfo>
using namespace std;

int main() {
    int x = 0, y = 1;
    float f = 2;

    if(typeid(x) == typeid(y)) {
        cout<< "x and y are of same type: "<< typeid(x).name()<< endl;
    }

    if(typeid(x) == typeid(f)) {
        cout<< "x and f are of same type: "<< typeid(f).name()<< endl;
    }

    return 0;
}
