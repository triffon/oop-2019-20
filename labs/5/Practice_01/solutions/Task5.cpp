#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::min;

struct Point {
    double x, y;

    void read() {
        cin >> x >> y;
    }

    void setPoint(double x, double y) {
        this->x = x;
        this->y = y;
    }

    void print() {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

struct Rectangular {
    Point a,b;

    void read() {
        cout << "Enter first point of rectangular" << endl;
        a.read();
        cout << "Enter second point of rectangular" << endl;
        b.read();
    }

    void print() {
        double minX = min(a.x, b.x);
        double maxX = max(a.x, b.x);
        double minY = min(a.y, b.y);
        double maxY = max(a.y, b.y);

        for (int i = 0; i < maxY; i++) {
            if (i >= minY) {
                for (int j = 0; j < maxX; j++) {
                    if (j >= minX) {
                        cout << '*';
                    } else {
                        cout << ' ';
                    }
                }
            }
            cout << endl;
        }
    }

    bool contains(Point point) {
        double minX = min(a.x, b.x);
        double maxX = max(a.x, b.x);
        double minY = min(a.y, b.y);
        double maxY = max(a.y, b.y);

        return minX <= point.x && maxX >= point.x && minY <= point.y && maxY >= point.y;
    }

    bool intersectingWith(Rectangular secondRectangle) {
        Point pointC, pointD;

        pointC.setPoint(secondRectangle.a.x, secondRectangle.b.y);
        pointD.setPoint(secondRectangle.b.x, secondRectangle.a.y);

        return this->contains(secondRectangle.a) || this->contains(secondRectangle.b) || this->contains(pointC) || this->contains(pointD);
    }
};

int main() {
    Rectangular firstRectangular, secondRectangular;
    Point givenPoint;

    cout << "Define rectangular A: " << endl;
    firstRectangular.read();

    cout << "Here it is: " << endl;
    firstRectangular.print();

    cout << "Enter point to be checked for being in rect. A: " << endl;

    givenPoint.read();

    cout << "It is " << (firstRectangular.contains(givenPoint) ? "" : "not ") << "in rectangular A" << endl;

    cout << "Define rectangular B: " << endl;
    secondRectangular.read();

    cout << "The two rectangulars are " << (firstRectangular.intersectingWith(secondRectangular)? "" : "not ") << "intersecting" << endl;

    return 0;
}
