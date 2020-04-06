#include <cassert>
#include "vector.hpp"

// --------------------- Private -----------------------

void Vector::clearData() {
	if (data == nullptr) {
		return;
	}

	delete[] data;
	data = nullptr;
	size = 0;
}

void Vector::copyData(const Rational* data, int size) {
	clearData();
	this->size = size;
	this->data = new Rational[size];
	for (int i = 0; i < size; ++i) {
		this->data[i] = data[i];
	}
}

// --------------------- Big Four -----------------------

Vector::Vector(Rational* data, int size): data(nullptr), size(size) {
	copyData(data, size);
}

Vector::Vector(const Vector& other): data(nullptr), size(other.size) {
	copyData(other.data, size);
}

Vector& Vector::operator=(const Vector& other) {
	if (this == &other) {
		return *this;
	}

	copyData(other.data, other.size);

	return *this;
}

Vector::~Vector() {
	clearData();
}

// -------------------- Public ----------------------------

void Vector::reserve(int capacity) {
	clearData();
	size = capacity;
	data = new Rational[capacity];
}

Rational Vector::dot(const Vector& other) const {
	Rational result(0);

	for (int i = 0; i < size; ++i) {
		result += data[i]*other[i];
	}

	return result;
}

// --------------------- Arithmetic -----------------------

Vector Vector::operator-() const {
	Vector result(*this);

	for (int i = 0; i < size; ++i) {
		data[i] = -data[i];
	}

	return result;
}

Vector& Vector::operator+=(const Vector& other) {
	(*this) = (*this) + other;
	return *this;
}

Vector& Vector::operator*=(const Rational& other) {
	(*this) = (*this) *= other;
	return *this;
}

Vector Vector::operator+(const Vector& other) const {
	assert(size == other.size);
	
	Vector res(*this);
	for (int i = 0; i < size; ++i) {
		res[i] += other[i];
	}

	return res;
}

Vector Vector::operator*(const Rational& scalar) const {
	Vector res(*this);
	for (int i = 0; i < size; ++i) {
		res[i] *= scalar;
	}

	return res;
}


// --------------------- Access -----------------------

Rational& Vector::operator[](int index) {
	return data[index];
}

const Rational& Vector::operator[](int index) const {
	return data[index];
}

// ------------------------ IO -------------------------

void Vector::print(ostream& out) const {
	if (size == 0) {
		return;
	}

	cout << "(" << data[0];
	for (int i = 1; i < size; ++i) {
		out << ", " << data[i];
	}
	cout << ")";
}

ostream& operator<<(ostream& out, const Vector& v) {
	v.print(out);
	return out;
}
