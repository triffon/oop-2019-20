#include <iostream>

#include "Shape.hpp"
#include "Triangle.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"
#include "Figures.hpp"

using std::cout;
using std::endl;

int main() {
  Triangle t(3,4,5);
  Rectangle r(6,8);
  Square s(2);

  Figures arr;
  arr.add(&t);
  arr.add(&r);
  arr.add(&s);

  cout << arr.getMaxPerimeter() << endl;
  cout << arr.getMaxArea() << endl;

  return 0;
}
