#include "DynamicArray.h"
#include <iostream>
#include <cassert>
using namespace std;
DynamicArray::DynamicArray()
{
    arr = new int[8];
    max = 8;
    size = 0;
}
int& DynamicArray::operator[](int index){
    checkForValidIndex(index);
    return arr[index];
}
void DynamicArray::checkForValidIndex(int index){
    assert(index>=0 && index<=size-1);
};
void DynamicArray::removeAt(int index){
    checkForValidIndex(index);
    for(int i=index;i<size-1;i++){
        arr[i] = arr[i+1];
    }
    size--;
    if(size<=((max*30)/100)){
        decrease();
    }
};
void DynamicArray::append(int element){
    if(size>=((max*70)/100)){
        increase();
    }
    arr[size] = element;
    size++;
};
void DynamicArray::increase(){
    cout << "increase" << endl;
    int * newArr = new int[max*2];
    for(int i=0;i<max;i++){
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    max*=2;
}
void DynamicArray::decrease(){
    cout << "decrease" << endl;
    int * newArr = new int[max/2];
    for(int i=0;i<max/2;i++){
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    max/=2;
}
//void DynamicArray::decrease()
int DynamicArray::getSize(){
    return size;
};
DynamicArray::~DynamicArray()
{
    delete[] arr;
}
