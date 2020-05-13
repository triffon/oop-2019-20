#include <iostream>
using namespace std;

template<typename T>
class Vector {
public:
	Vector(T data[] = NULL, int size = 0);
	Vector(const Vector& other);
	Vector<T>& operator=(const Vector<T>& other);
	~Vector();

	int getSize() const;
	const T& operator[](int index) const;
	T& operator[](int index);

	void append(const T& element);
private:
	T* data;
	int size;
	int capacity;

	void copyData(T* data, int size, int capacity = -1);
	void clearData();
};

template<typename T>
Vector<T>::Vector(T data[], int size) : data(NULL), size(size) {
	copyData(data, size);
}

template<typename T>
Vector<T>::Vector(const Vector& other) : data(NULL), size(other.size) {
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
inline void Vector<T>::append(const T& element) {
	if (size == capacity) {
		copyData(data, size, (capacity == 0 ? 10 : capacity * 2));
	}

	data[size++] = element;
}

template<typename T>
void Vector<T>::copyData(T* data, int size, int capacity) {
	if (data != this->data) {
		clearData();
	}

	this->size = size;
	this->capacity = capacity = (capacity == -1 ? size : capacity);
	this->data = new T[capacity];
	for (int i = 0; i < size; ++i) {
		this->data[i] = data[i];
	}
}

template<typename T>
void Vector<T>::clearData() {
	delete[] data;
	data = NULL;
	size = 0;
}

int main() {
    Vector<int> v;
    for (int i = 0; i < 15; ++i) {
        v.append(i);
    }

    for (int i = 0; i < 15; ++i) {
        cout << v[i]<< " ";
    }

    return 0;
}
