#include "Container.hpp"

template <typename T>
class Queue : public Container<T> {
    int capacity;
    int start;
    int end;
    T* arr;

    void resize() {
        T* tmp = new T[capacity * 2];
        for (int i = start; i < end; i++) {
            tmp[i] = arr[i];
        }
        delete[] arr;
        capacity *= 2;
        arr = tmp;
    }

    void shift() {
        for (int i = start; i < end; i++) {
            arr[i - start] = arr[i];
        }
        end -= start;
        start = 0;
    }

public:
    Queue() {
        start = end = 0;
        capacity = 8;
        arr = new T[capacity];
    }

    void push(T item){
        if (start > 0) {
            shift();
        } else if (end == capacity) {
            resize();
        }

        arr[end++] = item;
    }

    T pop() {
        return arr[start++];
    }

    T top() {
        return arr[start];
    }

    int size() {
        return end - start;
    }

    bool empty() {
        return end - start == 0;
    }

    ~Queue() {
        delete[] arr;
    }
};
