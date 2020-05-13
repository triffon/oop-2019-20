#include "Vector.h"
#include <sstream>
#include <iostream>

VectorN::VectorN(size_t dimensions) : f_size(dimensions)
{
	f_elements = new int[dimensions];
}

VectorN::VectorN(const VectorN& other)
{
	copy(other);
}

VectorN& VectorN::operator=(const VectorN& other)
{
	if (this != &other)
	{
		delete[] f_elements;
		copy(other);
	}

	return *this;
}

VectorN::~VectorN()
{
	delete[] f_elements;
}

std::string VectorN::toString() const
{
	std::stringstream ss;

	ss << "[";
	for (size_t i = 0; i < f_size - 1; i++)
	{
		ss << f_elements[i] << ", ";
	}
	ss << f_elements[f_size - 1] << "]";

	std::string result;
	std::getline(ss, result);

	return result;
}

VectorN& VectorN::operator+=(const VectorN& other)
{
	if (other.f_size > f_size)
	{
		resize(other.f_size);
	}

	size_t size = f_size > other.f_size
		? other.f_size
		: f_size;

	for (size_t i = 0; i < size; i++)
	{
		f_elements[i] += other.f_elements[i];
	}

	return *this;
}

VectorN& VectorN::operator-=(const VectorN& other)
{
	if (other.f_size > f_size)
	{
		resize(other.f_size);
	}

	size_t size = f_size > other.f_size
		? other.f_size
		: f_size;

	for (size_t i = 0; i < size; i++)
	{
		f_elements[i] -= other.f_elements[i];
	}

	return *this;
}

VectorN& VectorN::operator*=(const int scalar)
{
	for (size_t i = 0; i < f_size; i++)
	{
		f_elements[i] *= scalar;
	}

	return *this;
}

double VectorN::operator%(const VectorN& other) const
{
	double product = 1;
	if (f_size != other.f_size)
	{
		throw std::exception("Invalid dimensions.");
	}

	for (size_t i = 0; i < f_size; i++)
	{
		product += f_elements[i] * other.f_elements[i];
	}

	return product;
}

double VectorN::operator~() const
{
	return std::sqrt(operator%(*this));
}

bool VectorN::operator|=(const VectorN& other) const
{
	const double eps = 0.001;
	return abs(operator%(other)) < eps;
}

void VectorN::copy(const VectorN& other)
{
	f_size = other.f_size;
	f_elements = new int[f_size];
	for (size_t i = 0; i < f_size; i++)
	{
		f_elements[i] = other.f_elements[i];
	}
}

void VectorN::resize(size_t newSize)
{
	int* copy = new int[newSize];
	for (size_t i = 0; i < newSize; i++)
	{
		copy[i] = 0;
	}

	for (size_t i = 0; i < f_size; i++)
	{
		copy[i] = f_elements[i];
	}

	delete[] f_elements;
	f_elements = copy;
	f_size = newSize;
}

std::istream& operator>>(std::istream& in, VectorN& vector)
{
	in >> vector.f_size;

	delete[] vector.f_elements;
	vector.f_elements = new int[vector.f_size];
	for (size_t i = 0; i < vector.f_size; i++)
	{
		in >> vector.f_elements[i];
	}

	return in;
}

std::ostream& operator<<(std::ostream& out, const VectorN& vector)
{
	out << vector.f_size << " ";

	for (size_t i = 0; i < vector.f_size; i++)
	{
		out << vector.f_elements[i] << " ";
	}

	out << std::endl;

	return out;
}

VectorN operator+(const VectorN& lhs, const VectorN& rhs)
{
	VectorN result = lhs;
	result += rhs;

	return result;
}

VectorN operator-(const VectorN& lhs, const VectorN& rhs)
{
	VectorN result = lhs;
	result -= rhs;

	return result;
}

VectorN operator*(const VectorN& lhs, int scalar)
{
	VectorN result = lhs;
	result *= scalar;

	return result;
}

VectorN operator*(int scalar, const VectorN& rhs)
{
	return rhs * scalar;
}

