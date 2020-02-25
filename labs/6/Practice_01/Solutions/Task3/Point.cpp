//
// Created by yasen on 2/22/20.
//

#include <iostream>
#include "Point.h"

void enterPoint(Point& point) {
    std::cout << "Enter x and y of the point: " << std::endl;
    std::cin >> point.x >> point.y;
}


void printPoint(const Point& point) {
    std::cout << "( " << point.x << ", " << point.y << " ) ";
}
