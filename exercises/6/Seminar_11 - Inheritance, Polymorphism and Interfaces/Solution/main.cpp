#include <iostream>

#include "ShapesContainer.h"
#include "Rectangle.h"
#include "Square.h"
#include "Rectangle.h"
#include "EquilateralTriangle.h"
#include "IsoscelesTriangle.h"
#include "ScaleneTriangle.h"

int main()
{
	Point2D a = { 0,0 };
	Point2D b = { 1,1 };
	Point2D c = { 2,2 };
	ShapesContainer shapes;

	shapes.add(new Rectangle(a, b));
	shapes.add(new Square(a, 4));
	shapes.add(new EquilateralTriangle(a, b, c));
	shapes.add(new IsoscelesTriangle(a, b, c));
	shapes.add(new ScaleneTriangle(a, b, c));

	std::cout << shapes << std::endl;

	ShapesContainer secondShapes;
	std::ifstream in("shapes.txt");
	if (!in.is_open())
	{
		std::cout << "No :(" << std::endl;
		return 1;
	}

	in >> secondShapes;

	std::cout << std::endl << secondShapes;
}
