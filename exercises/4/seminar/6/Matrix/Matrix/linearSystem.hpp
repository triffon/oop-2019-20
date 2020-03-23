#include "matrix.hpp"

#pragma once

class LinearSystem {
	Matrix m;
	void rightTriangle();
public:
	LinearSystem(const Matrix& m);
	Rational* getSolution();
};