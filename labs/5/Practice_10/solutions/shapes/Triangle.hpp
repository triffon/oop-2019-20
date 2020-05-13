#pragma once
#include "Shape.hpp"

class Triangle : public Shape {
    double a, b, c;

public:
    Triangle(double a = 0, double b = 0, double c = 0);
    double getArea();
    double getPerimeter();
};
