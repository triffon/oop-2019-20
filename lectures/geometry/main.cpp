#include <iostream>
#include "point2d.hpp"
#include "point3d.hpp"

using DPoint2D = Point2D<double>;
// typedef Point2D<double> DPoint2D;

void testPoint3D() {
    Point3D p;
    Point3D q(1, 3, 8);
    p.printnl();
    q.printnl();
    q.translate(2, 1, 4);
    q.printnl();
    std::cout << q.distanceTo(p) << std::endl;
}


void testPoint2D() {
    // std::cout << "Hello, world!\n";
    DPoint2D p;
    DPoint2D q(1, 2);
    p.printnl();
    q.printnl();
    q.translate(q);
    q.translate(1, 0);
    q.printnl();
    std::cout << p.distanceTo(q) << std::endl;
    Point2D<int> r;
 // !!!   std::cout << p.distanceTo(r) << std::endl;
}

int main() {
    // testPoint2D();
    testPoint3D();
    return 0;
}