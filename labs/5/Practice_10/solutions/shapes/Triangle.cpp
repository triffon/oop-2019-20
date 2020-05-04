#include <iostream>
#include <cmath>
#include "Triangle.hpp"

Triangle::Triangle(double a, double b, double c) {
    this->a = a;
    this->b = b;
    this->c = c;
}

double Triangle::getPerimeter() {
    return a + b + c;
}

double Triangle::getArea() {
    double p = getPerimeter()/2;
    return sqrt(p * (p-a) * (p-b) * (p-c));
}
