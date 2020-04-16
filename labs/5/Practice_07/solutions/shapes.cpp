#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

class Shape {
    char type[32];

public:
    Shape() {
        strcpy(this->type, "\0");
    }

    Shape(char const* type) {
        strcpy(this->type, type);
    }

    void print() {
        cout << "type: " << type << endl;
    }
};

class Rectangular : Shape {
    int width;
    int height;

public:
    Rectangular(int width, int height) : Shape("rectangular") {
        this->width = width;
        this->height = height;
    }

    Rectangular(char const* type, int width, int height) : Shape(type) {
        this->width = width;
        this->height = height;
    }

    void print() {
        Shape::print();
        cout << "width: " << width << endl;
        cout << "height: " << height << endl;
    }
};

class ColoredRectangular : Rectangular {
    char color[32];

public:
    ColoredRectangular(char const* color, int width, int height) : Rectangular("colored rectangular", width, height) {
        strcpy(this->color, color);
    }

    void print() {
        Rectangular::print();
        cout << "color: " << color << endl;
    }
};

class Square : Shape {
    int side;

public:
    Square(int side) : Shape("square") {
        this->side = side;
    }

    void print() {
        Shape::print();
        cout << "side: " << side << endl;
    }
};

class Triangle : Shape {
    int side1, side2, side3;

public:
    Triangle(int side1, int side2, int side3) : Shape("triangle") {
        this->side1 = side1;
        this->side2 = side2;
        this->side3 = side3;
    }

    void print() {
        Shape::print();
        cout << "side1: " << side1 << endl;
        cout << "side2: " << side2 << endl;
        cout << "side3: " << side3 << endl;
    }
};

int main() {
    Shape shape;
    shape.print();
    cout << endl;

    Rectangular rect(2, 3);
    rect.print();
    cout << endl;

    ColoredRectangular coloredRect("red", 5, 6);
    coloredRect.print();
    cout << endl;

    Square square(4);
    square.print();
    cout << endl;

    Triangle triangle(3, 4, 5);
    triangle.print();

    return 0;
}
