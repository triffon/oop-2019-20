#pragma once

#include<fstream>

class Shape
{
public:
	Shape(bool _isInGroup) : isInGroup(_isInGroup) {}


protected:
	bool isInGroup;


public:
	virtual void print() const = 0;
	virtual void readFromFile( std::ifstream& stream ) = 0;
	virtual bool isInside( double, double ) const = 0;
	virtual void translate( double, double ) = 0;
	virtual const Shape* getShapeAt( size_t ) const = 0;

	virtual double getPerimeter() const = 0;
	virtual double getArea() const = 0;
	virtual Shape* clone() = 0;
};

