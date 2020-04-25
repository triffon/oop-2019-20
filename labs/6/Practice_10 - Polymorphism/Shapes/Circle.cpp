#define _USE_MATH_DEFINES
#include <math.h>
#include "Circle.h"

Circle::Circle(Point2D c, double r, bool isInGroup) :Shape(isInGroup), center(c), radius(r) {}

double Circle::getPerimeter() const
{
	double perimeter = 2 * M_PI * radius;
	return perimeter;
}

Shape* Circle::clone()
{
	return new Circle(*this);
}
