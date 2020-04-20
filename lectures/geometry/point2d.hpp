#ifndef __POINT2D_HPP
#define __POINT2D_HPP

#include <iostream>
#include <cmath>

template <typename T>
class Point2D {
// ниво 0:
    T x, y;
public:
// ниво 1:
    // конструктори
    Point2D() { x = y = 0; }
    Point2D(T const& _x, T const& _y) {
        x = _x;
        y = _y;
    }

    // селектори
    T getX() const { return x; }
    T getY() const { return y; }

    // мутатори
    void setX(T const& _x) { x = _x; }
    void setY(T const& _y) { y = _y; }

// ниво 2:
    void print() const;
    void printnl() const;
    double distanceToOrigin() const;
    double distanceTo(Point2D const& other) const;

    void translate(T const& dx, T const& dy);
    void translate(Point2D const& vec);
};

template <typename T>
void Point2D<T>::printnl() const {
    print();
    std::cout << std::endl;
}

template <typename T>
void Point2D<T>::print() const {
    std::cout << '(' << getX() << ", " << getY() << ')';
}

template <typename T>
double Point2D<T>::distanceToOrigin() const {
    return distanceTo(Point2D());
}

template <typename T>
double Point2D<T>::distanceTo(Point2D<T> const& other) const {
    return std::sqrt(
        std::pow(getX() - other.getX(), 2) +
        std::pow(getY() - other.getY(), 2)
    );
}

template <typename T>
void Point2D<T>::translate(T const& dx, T const& dy) {
    setX(getX() + dx); // x += dx;
    setY(getY() + dy); // y += dy;
}

template <typename T>
void Point2D<T>::translate(Point2D const& vec) {
    translate(vec.getX(), vec.getY());
    // TODO: първата чрез втората
}

#endif