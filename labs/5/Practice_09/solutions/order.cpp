#pragma once
#include <iostream>
#include "set.cpp"

template <typename T>
class Order : public Set<T> {
    using Set<T>::items;
    using Set<T>::count;

    void sort();
public:
    Order() : Set<T>::Set() {};
    void add(T const &);
};

template <typename T>
void Order<T>::sort() {
    for(int i = 0; i < count; i++) {
        for(int j = i+1; j < count; j++) {
            if(items[i] > items[j]) {
                T temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}

template <typename T>
void Order<T>::add(T const &temp) {
    Set<T>::add(temp);
    sort();
}
