
#include <iostream>
using namespace std;

class A {
    char* name;
public:
    A() {
        char temp[] = {'a', 's', 'd', 'f', '\0'};
        name = temp;
    }

    const char* getName() {
        return name;
    }
};

int main() {

    int x = 5;
    int* pX = &x;
    char* pC = reinterpret_cast<char*>(pX);


    cout<< *pC<< endl;

    const int* pCX = &x;
    //*pCX = 7;
    int* pMX = const_cast<int*>(pCX);
    *pMX = 7;

    cout<< *pCX<< endl;

    A a;
    char* name = const_cast<char*>(a.getName());
    name[3] = 'z';
    cout<< name<< endl;

    return 0;
}
