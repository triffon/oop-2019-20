#pragma once
#include <fstream>
#include <math.h>
class VectorN
{
public:
	VectorN(size_t dimensions = 0);
	VectorN(const VectorN& other);
	VectorN& operator=(const VectorN& other);
	~VectorN();
public:
	std::string toString() const;

public:
	VectorN& operator+=(const VectorN& other);
	VectorN& operator-=(const VectorN& other);
	VectorN& operator*=(const int scalar);
	double operator%(const VectorN& other)const;
	double operator~()const;
	bool operator|=(const VectorN& other)const;
public:
	friend std::istream& operator>>(std::istream& in, VectorN& vector);
	friend std::ostream& operator<<(std::ostream& out, const VectorN& vector);
private:
	void copy(const VectorN& other);
	void resize(size_t newSize);

private:
	int* f_elements;
	size_t f_size;
};

VectorN operator+(const VectorN& lhs, const VectorN& rhs);
VectorN operator-(const VectorN& lhs, const VectorN& rhs);

VectorN operator*(const VectorN& lhs, int scalar);
VectorN operator*(int scalar, const VectorN& rhs);

