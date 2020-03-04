#ifndef __POINT2D_HPP
#define __POINT2D_HPP

#include <iostream>

class Point2D {
// ниво 0:
    double x, y;
public:
// ниво 1:
    // конструктори
    Point2D() { x = y = 0; }
    Point2D(double _x, double _y) {
        x = _x;
        y = _y;
    }

    // селектори
    double getX() const { return x; }
    double getY() const { return y; }

    // мутатори
    void setX(double _x) { x = _x; }
    void setY(double _y) { y = _y; }

// ниво 2:
    void print() const;
    void printnl() const;
    double distanceToOrigin() const;
    double distanceTo(Point2D const& other) const;

    void translate(double dx, double dy);
    void translate(Point2D const& vec);
};

#endif