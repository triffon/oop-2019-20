#include "ArraySet.h"
#include "Utility.h"

using namespace Utility;

void ArraySet::copy(const ArraySet& other) {
	clear();
	data = new int[other.capacity];
	capacity = other.capacity;
	size = other.size;
	for (int i = 0; i < other.size; ++i) {
		data[i] = other.data[i];
	}
}

void ArraySet::clear() {
	delete[] data;
}

void ArraySet::expand() {
	int* newData = new int[capacity *= 2];
	for (int i = 0; i < size; ++i) {
		newData[i] = data[i];
	}
	delete[] data;
	data = newData;
}

int ArraySet::indexOf(const int& element) {
	return binarySearch(data, 0, size-1, element);
}

ArraySet::ArraySet(): data(new int[10]), size(0), capacity(10) {}

ArraySet::ArraySet(const ArraySet& other): data(nullptr), size(0), capacity(0) {
	copy(other);
}

ArraySet& ArraySet::operator=(const ArraySet& other) {
	if (this != &other) {
		copy(other);
	}

	return *this;
}

ArraySet::~ArraySet() {
	clear();
}

void ArraySet::insert(const int& element) {
	if (indexOf(element) != -1) {
		return;
	}

	if (size + 1 >= capacity) {
		expand();
	}

	if (size > 0 && element > data[size - 1]) {
		data[size++] = element;
		return;
	}

	int i = size-1;
	for (; i >= 0 && element > data[i]; --i) {
		data[i + 1] = data[i];
	}
	i = (i < 0) ? 0 : i;

	data[i] = element;
	++size;
}

void ArraySet::remove(const int& element) {
	int index = indexOf(element);

	if (index != -1) {
		for (int i = index; i < size-1; ++i) {
			data[i] = data[i + 1];
		}
		--size;
	}
}

const int* ArraySet::getElement(const int& element) {
	int index = indexOf(element);

	if (index != -1) {
		return &(data[index]);
	} else {
		return nullptr;
	}
}

void ArraySet::print() {
	for (int i = 0; i < size; ++i) {
		std::cout << data[i] << " ";
	}
	std::cout << std::endl;
}
