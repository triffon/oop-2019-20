#include <cassert>
#include "vector.hpp"

void Vector::copyData(Rational* data, int size) {
	clearData();

	this->data = new Rational[size];
	this->size = size;
	for (int i = 0; i < size; ++i) {
		this->data[i] = data[i];
	}
}

void Vector::clearData() {
	if (data == nullptr) {
		return;
	}

	delete[] data;
	data = nullptr;
	size = 0;
}

Vector::Vector(Rational* data, int size): data(nullptr), size(size) {
	copyData(data, size);
}

Vector::Vector(const Vector& other) : data(nullptr), size(other.size) {
	copyData(other.data, size);
}

Vector& Vector::operator=(const Vector& other) {
	if (this != &other) {
		copyData(other.data, other.size);
	}

	return *this;
}

Vector::~Vector() {
	clearData();
}

void Vector::reserve(int capacity) {
	clearData();
	data = new Rational[capacity];
	size = capacity;
}

Vector Vector::operator+(const Vector& other) const {
	Vector result(*this);

	for (int i = 0; i < size; ++i) {
		result[i] += other[i];
	}

	return result;
}

Vector Vector::operator*(const Rational& other) const {
	Vector result(*this);

	for (int i = 0; i < size; ++i) {
		result[i] *= other;
	}

	return result;
}

Vector& Vector::operator+=(const Vector& other) {
	(*this) = (*this) + other;
	return *this;
}

Vector& Vector::operator*=(const Rational& other) {
	(*this) = (*this) * other;
	return *this;
}

Rational& Vector::operator[](int index) {
	assert(index < size);
	return data[index];
}

const Rational& Vector::operator[](int index) const {
	return data[index];
}
