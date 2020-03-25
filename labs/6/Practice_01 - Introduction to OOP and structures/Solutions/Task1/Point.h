//
// Created by yasen on 2/22/20.
//

#ifndef TASK1_POINT_H
#define TASK1_POINT_H

struct Point {
    double x;
    double y;
};

void enterPoint(Point& point);
void printPoint(const Point& point);
double distanceFromCenter(const Point& p);
double distance(const Point& p1, const Point& p2);

#endif //TASK1_POINT_H
