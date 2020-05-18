#include <iostream>
using namespace std;

int& findElement(int* arr, int arrSize, int element) {
    for(int i = 0; i< arrSize; ++i) {
        if(arr[i] == 2) {
            throw 2;
        }

        if(arr[i] == element) {
            return arr[i];
        }
    }

    throw 1;
}

void printElement(int* arr, int arrSize, int element) {
    int& result = findElement(arr, arrSize, 6);
    cout<< result;
}

int main () {
    int arr[] = {1,2,3,4,5};
    int arrSize = 5;

    try {
        printElement(arr, arrSize, 4);
    } catch(int errorCode) {
        switch(errorCode) {
        case 1:
            cout<< "no such element";
        case 2:
            cout<< "there was 2";
        }
    }

    return 0;
}

