#include <iostream>
#include <cmath>
using namespace std;

struct Point {
// encapsulation - functionality that isn't required from the outside "world" isn't visible to it
//private: (uncommenting will show compilation errors)
    float x;
    float y;

public:
    // abstraction - the things that objects from this class can "do" are "abstracted out" in methods
    float dist(Point p) {
        float dx = x - p.x;
        float dy = y - p.y;
        return sqrt(dx*dx + dy*dy);
    }
};

// inheritance - the class Point3D "inherits" Point and gets all its variables and methods
struct Point3D: Point {
    float z;

    /*float dist(Point3D p) {
        float dx = x - p.x;
        float dy = y - p.y;
        float dz = z - p.z;
        return sqrt(dx*dx + dy*dy + dz*dz);
    }*/
};


int main () {
    Point p1, p2;

    cin>> p1.x>> p1.y;
    cin>> p2.x>> p2.y;

    cout<< p1.dist(p2);

    Point3D p3, p4;
    cin>> p3.x>> p3.y>> p3.z;
    cin>> p4.x>> p4.y>> p4.z;

    // polymorphism: the method of the base class "Point" will be used
    cout<< p3.dist(p4);

    return 0;
}
