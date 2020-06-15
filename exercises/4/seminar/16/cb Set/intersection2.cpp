#include <iostream>
using namespace std;

void intersection(int*& resArr, int& resSize, int* arr1, int size1, int* arr2, int size2) {

    if(size1< size2) {
        return intersection(resArr, resSize, arr2, size2, arr1, size1);
    }

    quickSort(arr1, 0, size1-1);

    resArr = new int[size1];
    resSize = 0;

    for(int i = 0; i< size1; ++i) {
        int index = binarySearch(arr2, 0, arrSize2-1, arr1[i]);
        if(index != -1) {
            resArr[resSize++] = arr1[i];
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
