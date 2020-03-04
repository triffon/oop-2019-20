#include <iostream>
#include "point2d.hpp"

void testGeometry() {
    std::cout << "Hello, world!\n";
    Point2D p;
    Point2D q(1, 2);
    p.printnl();
    q.printnl();
    q.translate(q);
    q.translate(1, 0);
    q.printnl();
    std::cout << p.distanceTo(q) << std::endl;
}

int main() {
    testGeometry();
    return 0;
}