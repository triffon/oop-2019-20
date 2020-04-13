#include "rational.hpp"
#pragma once

class Vector {
private:
	Rational* data;
	int size;

	void copyData(Rational* data, int size);
	void clearData();
public:
	Vector(Rational* data = nullptr, int size = 0);
	Vector(const Vector& other);
	Vector& operator=(const Vector& other);
	~Vector();

	void reserve(int capacity);

	Vector operator+(const Vector& other) const;
	Vector operator*(const Rational& other) const;

	Vector& operator+=(const Vector& other);
	Vector& operator*=(const Rational& other);

	Rational& operator[](int index);
	const Rational& operator[](int index) const;
};