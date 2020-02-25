#include <iostream>
#include "Rectangle.h"


int main() {

    Rectangle rect1;
    enterRect(rect1);

    Rectangle rect2;
    enterRect(rect2);

    Point p;
    enterPoint(p);

    std::cout << "Area of rect1 is: " << area(rect1) << std::endl;
    std::cout << "Area of rect2 is: " << area(rect2) << std::endl;
    std::cout << std::endl;

    std::cout << "Perimeter of rect1 is: " << perimeter(rect1) << std::endl;
    std::cout << "Perimeter of rect2 is: " << perimeter(rect2) << std::endl;
    std::cout << std::endl;

    printWithStars(rect1);
    printWithStars(rect2);

    if(pointInRectangle(p, rect1)) {
        std::cout << "Point: "; printPoint(p); std::cout << " is in rectangle: "; printRect(rect1);
    } else {
        std::cout << "Point: "; printPoint(p); std::cout << " is out of rectangle: "; printRect(rect1);
    }
    std::cout << std::endl;

    if(twoRectanglesIntersect(rect1, rect2)) {
        std::cout << "Rectangle "; printRect(rect1); std::cout << " intersect with "; printRect(rect2);
    } else {
        std::cout << "Rectangle "; printRect(rect1); std::cout << " it does not intersect with "; printRect(rect2);
    }


    return 0;
}