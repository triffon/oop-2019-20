#include <iostream>

using std::cout;
using std::endl;

/*
    Point2 -> Point3 -> ColPoint3
*/
class Point2 {

public:
    Point2(int _x, int _y) : x(_x), y(_y) {}
    virtual void print() const {
        cout << x << ", " << y;
    }

private:
    int x, y;

};

class Point3 : public Point2 {

public:
    Point3(int _x, int _y, int _z) : Point2(_x, _y), z(_z) {}
    void print() const {
        Point2::print();
        cout << ", " << z;
    }

private:
    int z;

};

class ColPoint3 : public Point3 {

public:
    ColPoint3(int _x, int _y, int _z, int _col) : Point3(_x, _y, _z), col(_col) {}
    void print() const {
        Point3::print();
        cout << ": color - " << col;
    }

private:
    int col;

};

int main() {
    Point2 p2(1, 2);
    Point3 p3(5, 6, 7);
    ColPoint3 cp3(8, 9, 10, 111);

    p3.print();
    cout << endl;
    Point2 * ptr1 = &p3;
    ptr1->print();
    cout << endl;

    Point2 * ptr2 = &cp3;
    ptr2->print();
    cout << endl;

    ((Point3 *)ptr1)->print();
    cout << endl;

    return 0;
}