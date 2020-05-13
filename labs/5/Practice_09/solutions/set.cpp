#pragma once
#include <iostream>

template <typename T>
class Set {
private:
    void copy(Set const &);
    void resize();

protected:
    T* items;
    int capacity;
    int count;

public:
    Set();
    Set(Set const &);
    ~Set();

    Set &operator=(Set const &);
    T &operator[](int);

    bool isEmpty();
    int size();
    void add(T const &);
    void remove(int);
};

template <typename T>
void Set<T>::copy(Set const &temp) {
    delete[] items;

    capacity = temp.capacity;
    count = temp.count;
    items = new T[capacity];

    for(int i=0; i<count; ++i) {
        items[i] = temp.items[i];
    }
}

template <typename T>
void Set<T>::resize() {
    capacity *= 2;
    T* newData = new T[capacity];
    for(int i = 0; i < count; i++) {
        newData[i] = items[i];
    }
    delete[] items;
    items = newData;
}

template <typename T>
Set<T>::Set() {
    capacity = 8;
    items = new T[capacity];
    count = 0;
}

template <typename T>
Set<T>::Set(Set const &temp) {
    copy(temp);
}

template <typename T>
Set<T>::~Set() {
    delete[] items;
}

template <typename T>
Set<T> &Set<T>::operator=(Set const &temp) {
    copy(temp);
    return *this;
}

template <typename T>
T& Set<T>::operator[](int i) {
    return items[i];
}

template <typename T>
bool Set<T>::isEmpty() {
    return !count;
}

template <typename T>
int Set<T>::size() {
    return count;
}

template <typename T>
void Set<T>::add(T const &temp) {
    for(int i = 0; i < count; i++) {
        if(items[i] == temp) {
            return;
        }
    }

    if(count == capacity) {
        resize();
    }

    items[count++] = temp;
}

template <typename T>
void Set<T>::remove(int ind) {
    if(ind < count) {
        count--;
        for(int i=ind; i<count; ++i) {
            items[i] = items[i+1];
        }
    }
}
