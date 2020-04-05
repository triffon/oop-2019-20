#include "rational.hpp"

#pragma once

class Vector {
private:
	int size;
	Rational* data;

	void clearData();
	void copyData(const Rational* data, int size);
public:
	Vector(Rational* data = nullptr, int n = 0);
	Vector(const Vector& other);
	Vector& operator=(const Vector& other);
	~Vector();

	void reserve(int capacity);
	Rational dot(const Vector& other) const;

	Vector operator-() const;

	Vector& operator+=(const Vector& other);
	Vector& operator*=(const Rational& other);

	Vector operator+(const Vector& other) const;
	Vector operator*(const Rational& scalar) const;

	Rational& operator[](int index);
	const Rational& operator[](int index) const;

	void print(ostream& out) const;
};

ostream& operator<<(ostream& out, const Vector& v);