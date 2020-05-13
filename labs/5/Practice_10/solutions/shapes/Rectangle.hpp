#pragma once
#include "Shape.hpp"

class Rectangle : public Shape {
    double width;
    double height;

public:
    Rectangle(double w = 0, double h = 0);
    double getArea();
    double getPerimeter();
};
