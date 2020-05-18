#include <iostream>
using namespace std;

int& findElement(int* arr, int arrSize, int element) {
    for(int i = 0; i< arrSize; ++i) {
        if(arr[i] == element) {
            return arr[i];
        }
    }

    throw "no such index";
}

int main () {
    int arr[] = {1,2,3,4,5};
    int arrSize = 5;

    try {
        int& result = findElement(arr, arrSize, 6);
        cout<< result;
    } catch(const char* error) {
        cout<< error<< endl;
    }

    return 0;
}
