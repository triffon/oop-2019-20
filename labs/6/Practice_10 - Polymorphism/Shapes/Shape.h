#pragma once

class Shape
{
protected:
	bool isInGroup;

	Shape(bool _isInGroup) : isInGroup(_isInGroup) {}

public:
	virtual double getPerimeter() const = 0;
	virtual double getArea() const = 0;
	virtual Shape* clone() = 0;
};

