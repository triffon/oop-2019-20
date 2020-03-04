#include <cmath>

#include "point2d.hpp"

 void Point2D::printnl() const {
    print();
    std::cout << std::endl;
}

void Point2D::print() const {
    std::cout << '(' << getX() << ", " << getY() << ')';
}

double Point2D::distanceToOrigin() const {
    return distanceTo(Point2D());
}

double Point2D::distanceTo(Point2D const& other) const {
    return std::sqrt(
        std::pow(getX() - other.getX(), 2) +
        std::pow(getY() - other.getY(), 2)
    );
}

void Point2D::translate(double dx, double dy) {
    setX(getX() + dx); // x += dx;
    setY(getY() + dy); // y += dy;
}

void Point2D::translate(Point2D const& vec) {
    translate(vec.getX(), vec.getY());
    // TODO: първата чрез втората
}