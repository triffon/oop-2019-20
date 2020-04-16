#pragma once
#include <iostream>
using namespace std;

const int DEFAULT_SIZE = 5;

template <typename T>
class Vector
{
	T* arr;
	int currentSize;
	int currentIdx;

	void copy(const Vector& other);
	void resizeArray();
public:
	Vector();
	Vector(int size);
	Vector(const Vector<T>& other);
	Vector& operator=(const Vector<T>& other);
	~Vector();

	const T& operator[](int idx) const; // when it is called from const reference
	T& operator[](int idx);

	int getLength() const { return currentIdx; }

	void add(T element);
	void remove(int index);
};

template <typename T>
void Vector<T>::copy(const Vector& other)
{
	currentSize = other.currentSize;
	currentIdx = other.currentIdx;
	arr = new T[currentSize];
	for (int idx = 0; idx < currentIdx; ++idx) {
		arr[idx] = other.arr[idx];
	}
}

template <typename T>
Vector<T>::Vector() {
	arr = new T[DEFAULT_SIZE];
	currentSize = DEFAULT_SIZE;
	currentIdx = 0;
}

template <typename T>
Vector<T>::Vector(int size) {
	arr = new T[size];
	currentSize = size;
	currentIdx = 0;
}

template <typename T>
Vector<T>::Vector(const Vector& other)
{
	copy(other);
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
	if (this == &other)
		return *this;
	delete[] arr;
	copy(other);
	return *this;
}

template <typename T>
Vector<T>::~Vector()
{
	delete[] arr;
}

template <typename T>
const T& Vector<T>::operator[](int idx) const {
	return arr[idx];
}

template <typename T>
T& Vector<T>::operator[](int idx) {
	return arr[idx];
}

template <typename T>
void Vector<T>::resizeArray() {
	T* temp = new T[currentSize * 2];
	for (int idx = 0; idx < currentIdx; ++idx) {
		temp[idx] = arr[idx];
	}
	delete[] arr;
	arr = temp;
	currentSize *= 2;
}

template <typename T>
void Vector<T>::add(T element)
{
	if (currentIdx == currentSize) {
		resizeArray();
	}
	arr[currentIdx++] = element;
}

template <typename T>
void Vector<T>::remove(int index) {
	if (index < 0 || index >= currentIdx) {
		return;
	}

	for (int i = index; i < currentIdx - 1; ++i) {
		arr[i] = arr[i + 1];
	}
	--currentIdx;
}
