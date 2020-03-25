//
// Created by yasen on 2/22/20.
//

#include <iostream>
#include <cmath>
#include "Point.h"


void enterPoint(Point& point) {
    std::cin >> point.x >> point.y;
}

void printPoint(const Point& point) {
    std::cout << "( " << point.x << ", " << point.y << " )" << std::endl;
}

double distanceFromCenter(const Point& p) {
    return sqrt( p.x*p.x + p.y*p.y );
}
double distance(const Point& p1, const Point& p2) {
    return sqrt( (p1.x-p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y) );
}

