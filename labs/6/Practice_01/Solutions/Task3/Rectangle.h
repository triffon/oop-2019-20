//
// Created by yasen on 2/22/20.
//

#ifndef TASK3_RECTANGLE_H
#define TASK3_RECTANGLE_H

#include "Point.h"

#define min(x, y) ((x < y) ? x : y)
#define max(x, y) ((x > y) ? x : y)

struct Rectangle{
    Point p;
    Point q;
};

void enterRect(Rectangle&);
void printRect(const Rectangle&);
double area(const Rectangle&);
double perimeter(const Rectangle&);
void printWithStars(const Rectangle&);
bool pointInRectangle(const Point&, const Rectangle&);
bool twoRectanglesIntersect(const Rectangle&, const Rectangle&);

#endif //TASK3_RECTANGLE_H
