#pragma once

template<typename T>
class Vector {
public:
	Vector(T data[] = nullptr, int size = 0);
	Vector(const Vector& other);
	Vector<T>& operator=(const Vector<T>& other);
	~Vector();

	int getSize() const;
	const T& operator[](int index) const;
	T& operator[](int index);
private:
	T* data;
	int size;

	void copyData(T* data, int size);
	void clearData();
};

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
inline int Vector<T>::getSize() const {
	return size;
}

template<typename T>
inline const T& Vector<T>::operator[](int index) const {
	return data[index];
}

template<typename T>
inline T& Vector<T>::operator[](int index) {
	return data[index];
}

template<typename T>
void Vector<T>::copyData(T* data, int size) {
	clearData();
	this->size = size;
	this->data = new T[size];
	for (int i = 0; i < size; ++i) {
		this->data[i] = data[i];
	}
}

template<typename T>
void Vector<T>::clearData() {
	delete[] data;
	data = nullptr;
	size = 0;
}