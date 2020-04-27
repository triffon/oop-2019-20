/*#include "Vector.h"

template<typename T>
Vector<T>::Vector(T data[], int size) : data(nullptr), size(size) {
	copyData(data, size);
}

template<typename T>
Vector<T>::Vector(const Vector& other) : data(nullptr), size(other.size) {
	copyData(other.data, other.size);
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
	if (&other == this) {
		return *this;
	}

	copyData(other.data, other.size);
	return *this;
}

template<typename T>
Vector<T>::~Vector() {
	clearData();
}

template<typename T>
void Vector<T>::copyData(T* data, int size) {
	clearData();
	this->size = size;
	for (int i = 0; i < size; ++i) {
		this->data[i] = data[i];
	}
}

template<typename T>
void Vector<T>::clearData() {
	delete[] data;
	size = 0;
}*/