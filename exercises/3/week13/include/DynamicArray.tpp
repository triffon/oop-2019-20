#include "DynamicArray.h"
#include <iostream>
#include <cassert>
using namespace std;
template<class T>
DynamicArray<T>::DynamicArray()
{
    arr = new T[8];
    max = 8;
    size = 0;
}
/// specialization for ints
template<>
DynamicArray<int>::DynamicArray()
{
    arr = new int[8];
    max = 8;
    size = 0;
    cout << "Wow... dynamic array out of ints. How trivial!" << endl;
}
template<class T>
T& DynamicArray<T>::operator[](int index){
    checkForValidIndex(index);
    return arr[index];
}
template<class T>
void DynamicArray<T>::checkForValidIndex(int index){
    assert(index>=0 && index<=size-1);
};
template<class T>
void DynamicArray<T>::removeAt(int index){
    checkForValidIndex(index);
    for(int i=index;i<size-1;i++){
        arr[i] = arr[i+1];
    }
    size--;
    if(size<=((max*30)/100)){
        decrease();
    }
};
template<class T>
void DynamicArray<T>::append(T element){
    if(size>=((max*70)/100)){
        increase();
    }
    arr[size] = element;
    size++;
};
template<class T>
Iterator<T>* DynamicArray<T>::begin(){
    DynamicArrayIterator<T>* dai = new DynamicArrayIterator<T>();
    dai->base = arr;
    dai->position = 0;
    dai->size = size;
   return dai; 
};
template<class T>
void DynamicArray<T>::increase(){
    cout << "increase" << endl;
    T * newArr = new T[max*2];
    for(int i=0;i<max;i++){
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    max*=2;
}
template<class T>
void DynamicArray<T>::decrease(){
    cout << "decrease" << endl;
    T * newArr = new T[max/2];
    for(int i=0;i<max/2;i++){
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    max/=2;
}
template<class T>
int DynamicArray<T>::getSize(){
    return size;
};
template<class T>
DynamicArray<T>::~DynamicArray()
{
    delete[] arr;
}
