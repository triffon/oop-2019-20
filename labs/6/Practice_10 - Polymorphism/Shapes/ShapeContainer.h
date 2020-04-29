#pragma once
#include "Shape.h"
#include <fstream>

class ShapeContainer
{
public:
	ShapeContainer(size_t capacity = 16);
	ShapeContainer(const ShapeContainer& other);
	ShapeContainer& operator=(const ShapeContainer& other);
	~ShapeContainer();

public:
	void printPerimeters() const;
	void add(Shape* newShape);

	friend std::ifstream& operator>>(std::ifstream& in, ShapeContainer& container);

private:
	void copy(const ShapeContainer& other);
	void clean();
	void resize(size_t newCapacity);

private:
	Shape** f_shapes;
	size_t f_size;
	size_t f_capacity;
};

