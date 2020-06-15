#include <iostream>
using namespace std;

void intersection(int*& resArr, int& resSize, int* arr1, int size1, int* arr2, int size2) {
    resArr = new int[(size1 < size2) ? size1 : size2];
    resSize = 0;
    for(int i = 0; i< size1; ++i) {
        for(int j = 0; j< size2; ++j) {
            if(arr1[i] == arr2[j]) {
                resArr[resSize++] = arr1[i];
            }
        }
    }
}

int main() {
    int* arr;
    int sz;

    int arr1[5] = {15, -254, 1, 14, 1543};
    int arr2[10] = {1, 2, 3, 1235, 14, -1234, 532, 634, 94, -254};

    intersection(arr, sz, arr1, 5, arr2, 10);
    for(int i = 0; i< sz; ++i) {
        cout<< arr[i]<< " ";
    }
    cout<< endl;

    delete[] arr;

    return 0;
}
