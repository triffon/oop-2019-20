#include "point3d.hpp"

void Point3D::print() const {
    std::cout << '(' << getX() << ", " << getY() << ", " << getZ() << ')';
}

void Point3D::printnl() const {
    print();
    std::cout << std::endl;
}

double Point3D::distanceToOrigin() const {
    return distanceTo(Point3D());
}

double Point3D::distanceTo(Point3D const& other) const {
    Point2D q1(getP().distanceToOrigin(), getZ()),
            q2(other.getP().distanceToOrigin(), other.getZ());
    return q1.distanceTo(q2);
    // TODO: да се реализира distanceTo чрез distanceTo
    /*
    return std::sqrt(
        std::pow(getP().distanceTo(other.getP()), 2) +
        std::pow(getZ() - other.getZ(), 2)
    );
    */
}

void Point3D::translate(double dx, double dy, double dz) {
    translate(Point3D(dx, dy, dz));
}

void Point3D::translate(Point3D const& vec) {
    setX(getX() + vec.getX());
    setY(getY() + vec.getY());
    setZ(getZ() + vec.getZ());
}