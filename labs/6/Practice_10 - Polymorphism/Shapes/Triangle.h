#pragma once
#include "Shape.h"
#include "Point2D.hpp"

class Triangle : public Shape
{
public:
	Triangle(Point2D _a, Point2D _b, Point2D _c);

public:
	double getPerimeter() const override;
	Shape* clone();
private:
	Point2D a;
	Point2D b;
	Point2D c;
};

