#pragma once
#include "Triangle.h"
#include "MathFormulas.hpp"

Triangle::Triangle(Point2D _a, Point2D _b, Point2D _c) : a(_a), b(_b), c(_c) {}

double Triangle::getPerimeter() const
{
	double distanceAB = Formulas::getDistance2D(a, b);
	double distanceAC = Formulas::getDistance2D(a, c);
	double distanceBC = Formulas::getDistance2D(b, c);

	double perimeter = distanceAB + distanceAC + distanceBC;
	return perimeter;
}

Shape* Triangle::clone()
{
	return new Triangle(*this);
}
