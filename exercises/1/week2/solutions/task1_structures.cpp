#include <iostream>
#include <cassert>
using namespace std;

struct DynArray {
    int* data;
    int size;
    int capacity;
};

DynArray create(int initialCapacity = 2) {
	DynArray dynArray;
    dynArray.capacity = initialCapacity;
    dynArray.size = 0;
    dynArray.data = new int[dynArray.capacity];

    return dynArray;
}

void resize(DynArray& arr) {
	arr.capacity *= 2;

    int* old = arr.data;
    arr.data = new int[arr.capacity];

    for (int i = 0; i < arr.size; i++) {
        arr.data[i] = old[i];
    }

    delete[] old;
}


void push_back(DynArray& arr, int element) {
	if (arr.size == arr.capacity) {
        resize(arr);
    }
    
    arr.data[arr.size++] = element;
}

void pop_back(DynArray& arr) {
	arr.size--;
}

void remove(DynArray& arr, int index) {
	assert(index >= 0 && index < arr.size);

    for (int i = index; i < arr.size - 1; i++) {
        arr.data[i] = arr.data[i + 1];
    }

    arr.size--;
}

int get(DynArray& arr, int index) {
	assert(index >= 0 && index < arr.size);

    return arr.data[index];
}

void print(DynArray& arr) {
	 cout << "DynArray: \n";
    cout << "\tsize: " << arr.size << endl;
    cout << "\telements: \n";
    
    for (int i = 0; i < arr.size; i++) {
        cout << "\t\t" << get(arr, i) << endl;
    }
}


int main() {

    DynArray dynArray = create(2);
    push_back(dynArray, 12);
    push_back(dynArray, -8);
    push_back(dynArray, 777);
    push_back(dynArray, 7);
    push_back(dynArray, 7777777);
    push_back(dynArray, -17);

    print(dynArray);
    remove(dynArray, 2);
    pop_back(dynArray);


    cout << endl;
    print(dynArray);

    return 0;
}
