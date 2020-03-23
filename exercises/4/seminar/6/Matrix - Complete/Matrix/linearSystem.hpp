#include <iostream>
#include "rational.hpp"
#include "matrix.hpp"
using namespace std;
#pragma once

class LinearSystem {
	Matrix m;
	void rightTriangle();
public:
	LinearSystem(const Matrix& m);
	Rational* getSolution();

	void print(ostream& out) const;
	void read(istream& in);
};

ostream& operator<<(ostream& out, const LinearSystem& ls);
istream& operator>>(istream& in, LinearSystem& ls);