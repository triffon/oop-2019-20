#pragma once
#include <iostream>
#include "Shape.hpp"

class Figures {
    Shape** shapes;
    int count;
    int size;
    void resize();

public:
    Figures();
    void add(Shape* const shape);
    double getMaxPerimeter();
    double getMaxArea();
};
