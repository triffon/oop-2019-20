#include "Container.hpp"

template <typename T>
class Stack : public Container<T> {
    int capacity;
    int length;
    T* arr;

    void resize() {
        T* tmp = new T[capacity * 2];
        for (int i = 0; i < length; i++) {
            tmp[i] = arr[i];
        }
        delete[] arr;
        capacity *= 2;
        arr = tmp;
    }

public:
    Stack() {
        length = 0;
        capacity = 8;
        arr = new T[capacity];
    }

    void push(T item){
        if (length == capacity) {
            resize();
        }

        arr[length++] = item;
    }

    T pop() {
        return arr[--length];
    }

    T top() {
        return arr[length - 1];
    }

    int size() {
        return length;
    }

    bool empty() {
        return length == 0;
    }

    ~Stack() {
        delete[] arr;
    }
};
