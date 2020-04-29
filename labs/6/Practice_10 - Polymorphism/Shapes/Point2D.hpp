#pragma once
#include <fstream>

struct Point2D
{
	double x;
	double y;

	friend std::ifstream& operator>>(std::ifstream& in, Point2D& point);
	Point2D(double _x = 0, double _y = 0) : x(_x), y(_y) {	}
};

inline std::ifstream& operator>>(std::ifstream& in, Point2D& point)
{
	in >> point.x >> point.y;

	return in;
}

