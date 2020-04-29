#pragma once
#include <math.h>
#include "Point2D.hpp"

class Formulas
{
public:
	static double getDistance2D(Point2D a, Point2D b)
	{
		double result = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
		return result;
	}
};
