#pragma once
#include "Shape.h"
#include "Point2D.hpp"

class Circle : public Shape
{
public:
	Circle(Point2D c, double r, bool isInGroup);

public:
	double getPerimeter() const override;
	double getArea() const override;

	Shape* clone();

private:
	Point2D center;
	double radius;
};

