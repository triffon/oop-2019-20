#pragma once
#include "Shape.h"
#include "Point2D.hpp"

class Rectangle : public Shape
{
public:
	Rectangle(Point2D bottom, Point2D upper);

public:
	virtual double getPerimeter() const override;
	virtual Shape* clone() override;

private:
	Point2D bottomLeft;
	Point2D upperRight;
};

