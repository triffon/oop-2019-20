#include <iostream>
#include <math.h>

using std::cout;
using std::cin;
using std::endl;

struct Point {
    double x, y;

    void read() {
        cout << "X: "; cin >> x;
        cout << "Y: "; cin >> y;
    }

    void print() {
        cout << "(" << x << "," << y << ")" << endl;
    }

    double distance() {
        return sqrt(x*x + y*y);
    }

    double distanceFrom(Point other) {
        double deltaX = x - other.x;
        double deltaY = y - other.y;

        return sqrt(deltaX*deltaX + deltaY*deltaY);
    }
};

int main() {

    Point point1, point2;

    point1.x = 3;
    point1.y = 4;

    cout << "Point 1: ";
    point1.print();

    cout << "Distance of Point 1 from (0,0): " << point1.distance() << endl;

    point2.read();

    cout << "Distance of Point 1 from Point 2: " << point1.distanceFrom(point2) << endl;

    return 0;
}
