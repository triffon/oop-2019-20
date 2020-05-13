#include <iostream>
#include "Rectangle.hpp"

Rectangle::Rectangle(double w, double h) {
  width = w;
  height = h;
}

double Rectangle::getPerimeter() {
    return 2 * (width + height);
}

double Rectangle::getArea() {
    return width * height;
}
