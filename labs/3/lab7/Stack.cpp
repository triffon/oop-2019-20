//
// Created by tony on 16.04.20 г..
//

#include "Stack.h"
template <class T>
Stack<T>::Stack(): size(0), capacity(8){
    data = new T[capacity];
}

template <class T>
Stack<T>::Stack(int _capacity): size(0), capacity(_capacity){
    data = new T[capacity];
}

template <class T>
Stack<T>::~Stack(){
    clean();
}

template <class T>
void Stack<T>::copy(const Stack<T> &other) {
    size = other.size;
    capacity = other.capacity;
    data = new T[capacity];
    for(int i = 0; i < size; i++){
        data[i] = other.data[i];
    }
}

template <class T>
void Stack<T>::clean() {
    delete[] data;
    data = nullptr;
}

template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T> &other) {
    if(this != &other){
        clean();
        copy(other);
    }
    return *this;
}

template <class T>
void Stack<T>::resize() {
    capacity *= 2;
    T* newData = new T[capacity];
    for(int i = 0; i < size; i++){
        newData[i] = data[i];
    }
    clean();
    data = newData;
}

template<typename T>
Stack<T>::Stack(const Stack &other) {
    copy(other);
}

template <typename T>
void Stack<T>::push(T toPush) {
    if(size == capacity){
        resize();
    }
    data[size++] = toPush;
}

template <class T>
bool Stack<T>::empty() const {
    return size == 0;
}

template <class T>
T Stack<T>::pop() {
    if (!empty()) {
        return data[size--];
    }
}

template <typename P>
int Stack<P>::getSize() const {
    return size;
}

template <typename T>
T Stack<T>::top() const {
    return data[size];
}