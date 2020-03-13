#include <iostream>
using namespace std;

int main() {
    char* arr = new char[10];
    for(int i = 0; i< 9; ++i) {
        arr[i] = 'a' + i;
    }
    arr[9] = '\0';
    cout<< arr<< endl;
    if(true) {
        char* arr2 = arr;
        delete [] arr2;
    }
    cout<< arr<< endl;

    return 0;
}
