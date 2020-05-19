#include <iostream>

using std::cout;
using std::endl;

/*
             Shape
            /  |  \
           /   |   \
   Rectangle Square  Circle
*/

class Shape {

public:
    void print() const {
        cout << "Shape: ";
        spec();
        cout << endl;
    }
    virtual void spec() const {
        cout << "unspecified";
    }

};

class Rectangle : public Shape {

public:
    void spec() const {
        cout << "rectangle";
    }

};

class Square : public Shape {

public:
    void spec() const {
        cout << "square";
    }

};

class Circle : public Shape {

public:
    void spec() const {
        cout << "circle";
    }

};

int main() {
    Rectangle s1; s1.print();
    s1.spec(); cout << endl;
    Square s2; s2.print();
    Circle s3; s3.print();

    Shape * ptr;
    ptr = &s1;
    ptr->spec();
    cout << endl;
    ptr->Shape::spec();
    cout << endl;

    return 0;
}