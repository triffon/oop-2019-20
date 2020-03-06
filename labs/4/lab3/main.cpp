#include <iostream>
#include <cstdlib>
using namespace std;


class IntArray {
    int* arr;
    int currentIdx;
    int currentSize;

public:
    IntArray() {
        cout << "Default constructor called" << endl;
        currentSize = 5;
        arr = new int[currentSize];
        currentIdx = 0;
    }

    IntArray(int size) {
        cout << "Custom constructor called" << endl;
        currentSize = size;
        arr = new int[currentSize];
        currentIdx = 0;
    }

    IntArray(const IntArray& other) {
        cout << "Copy constructor called" << endl;
        copyArray(other);
    }

    IntArray& operator= (const IntArray& other) {
        cout << "Operator = called" << endl;
        if (this != &other) {
            delete[] arr;
            copyArray(other);
        }
        return *this;
    }

    ~IntArray() {
        cout << "Destructor called" << endl;
        delete[] arr;
    }

    void addElement(int elem) {
        if(isFull()) {
            resizeArray();
        }

        arr[currentIdx++] = elem;
    }

    int& operator[] (int idx) {
        return arr[idx];
    }

    void print() {
        for(int i = 0; i < currentIdx; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

private:
    void copyArray(const IntArray& other) {
        currentIdx = other.currentIdx;
        currentSize = other.currentSize;
        arr = new int[currentSize];

        for(int i = 0; i < currentIdx; i++) {
            arr[i] = other.arr[i];
        }
    }

    bool isFull() {
        return currentIdx == currentSize;
    }

    void resizeArray() {
        currentSize *= 2;
        int* newArr = new int[currentSize];
        for(int i = 0; i < currentIdx; i++) {
            newArr[i] = arr[i];
        }

        delete[] arr;
        arr = newArr;

        cout << "Array resized to: " << currentSize << endl;
    }
};

int main()
{
    IntArray arr(1);
    arr.addElement(1);
    arr.addElement(2);
    arr.addElement(3);
    arr.addElement(4);
    arr.addElement(5);
    arr.addElement(6);
    arr.addElement(7);

    arr.print();

    arr[1] = 20;
    arr[2] = 50;

    arr.print();

    IntArray arr2(arr);
    arr2.addElement(10);
    arr2.print();
    arr.print();
    IntArray arr3;
    arr3 = arr2;
    arr3.addElement(11);
    arr3.print();
    arr2.print();
    return 0;
}
