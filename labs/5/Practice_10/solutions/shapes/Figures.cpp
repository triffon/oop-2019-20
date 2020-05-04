#include <iostream>
#include "Figures.hpp"

Figures::Figures() {
    count = 0;
    size = 8;
    shapes = new Shape*[8];
}

void Figures::resize() {
    size *= 2;
    Shape** newShapes = new Shape*[size];
    for(int i = 0; i < count; i++) {
        newShapes[i] = shapes[i];
    }
    delete[] shapes;
    shapes = newShapes;
}

void Figures::add(Shape* const shape) {
    if (count == size) {
        resize();
    }

    shapes[count++] = shape;
}

double Figures::getMaxPerimeter() {
    double mx = shapes[0]->getPerimeter();

    for(int i = 1; i < count; i++) {
        if(mx < shapes[i]->getPerimeter()) {
            mx = shapes[i]->getPerimeter();
        }
    }

    return mx;
}

double Figures::getMaxArea() {
    double mx = shapes[0]->getArea();

    for(int i = 1; i < count; i++) {
        if(mx < shapes[i]->getArea()) {
            mx = shapes[i]->getArea();
        }
    }

    return mx;
}

