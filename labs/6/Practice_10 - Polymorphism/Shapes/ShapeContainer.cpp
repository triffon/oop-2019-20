#pragma once

#include <iostream>
#include <string>

#include "Point2D.hpp"
#include "ShapeContainer.h"
#include "Triangle.h"
#include "Circle.h"
#include "Rectangle.h"

using std::string;

ShapeContainer::ShapeContainer(size_t capacity) : f_capacity(capacity), f_size(0)
{
	f_shapes = new Shape * [capacity];
}

ShapeContainer::ShapeContainer(const ShapeContainer& other)
{
	copy(other);
}

ShapeContainer& ShapeContainer::operator=(const ShapeContainer& other)
{
	if (this != &other)
	{
		clean();
		copy(other);
	}

	return *this;
}

ShapeContainer::~ShapeContainer()
{
	clean();
}

void ShapeContainer::printPerimeters() const
{
	for (size_t i = 0; i < f_size; i++)
	{
		std::cout << f_shapes[i]->getPerimeter() << std::endl;
	}
}

void ShapeContainer::printArea() const
{
	for (size_t i = 0; i < f_size; i++)
	{
		std::cout << f_shapes[i]->getArea() << std::endl;
	}
}

void ShapeContainer::add(Shape* newShape)
{
	if (f_size >= f_capacity)
	{
		resize(f_capacity * 2);
	}

	f_shapes[f_size] = newShape;
	f_size++;
}

void ShapeContainer::copy(const ShapeContainer& other)
{
	f_size = other.f_size;
	f_capacity = other.f_capacity;
	f_shapes = new Shape * [f_capacity];

	for (size_t i = 0; i < f_size; i++)
	{
		f_shapes[i] = other.f_shapes[i]->clone();
	}
}

void ShapeContainer::clean()
{
	for (size_t i = 0; i < f_size; i++)
	{
		delete f_shapes[i];
	}

	delete[] f_shapes;
}

void ShapeContainer::resize(size_t newCapacity)
{
	if (newCapacity < f_capacity)
	{
		return;
	}

	f_capacity = newCapacity;
	Shape** newShapes = new Shape * [f_capacity];

	for (size_t i = 0; i < f_size; i++)
	{
		newShapes[i] = f_shapes[i];
	}

	delete[] f_shapes;
	f_shapes = newShapes;
}

std::ifstream& operator>>(std::ifstream& in, ShapeContainer& container)
{
	bool isInGroup = false;
	string type;
	while (in >> type)
	{

		if (type == "triangle")
		{
			Point2D a, b, c;
			in >> a >> b >> c;

			container.add(new Triangle(a, b, c));
		}
		else if (type == "rect")
		{
			Point2D bottomLeft, upperRight;
			in >> bottomLeft >> upperRight;

			container.add(new Rectangle(bottomLeft, upperRight));
		}
		else if (type == "circle")
		{
			Point2D center;
			double radius;
			in >> center >> radius;

			container.add(new Circle(center, radius, isInGroup));
		}
		else if (type == "group")
		{
			string inWord;
			in >> inWord;
			if (inWord == "in")
			{
				isInGroup = true;
			}
			else if (inWord == "out")
			{
				isInGroup = false;
			}
		}
	}

	return in;
}
