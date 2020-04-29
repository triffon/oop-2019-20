#include "Rectangle.h"
#include "MathFormulas.hpp"

Rectangle::Rectangle(Point2D bottom, Point2D upper) :bottomLeft(bottom), upperRight(upper) {}

double Rectangle::getPerimeter() const
{
	double width = abs(upperRight.x - bottomLeft.x);
	double height = abs(upperRight.y - bottomLeft.y);

	double perimeter = 2 * (width + height);
	return perimeter;
}

Shape* Rectangle::clone()
{
	return new Rectangle(*this);
}
