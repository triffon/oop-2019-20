//
// Created by yasen on 2/22/20.
//


#include <iostream>
#include "Rectangle.h"

void enterRect(Rectangle& rect) {
    std::cout << "Enter a rectangle's two point" << std::endl;
    enterPoint(rect.p);
    enterPoint(rect.q);
}

void printRect(const Rectangle& rect) {
    std::cout << "[ "; printPoint(rect.p); std::cout << ", "; printPoint(rect.q); std::cout << " ]";
}

double area(const Rectangle& rect) {
    return (rect.q.x - rect.p.x) * (rect.p.y - rect.q.y);
}

double perimeter(const Rectangle& rect) {
    return ((rect.q.x - rect.p.x) + (rect.p.y - rect.q.y)) * 2;
}

void printWithStars(const Rectangle& rect) {
    unsigned firstSide = (unsigned )(rect.q.x - rect.p.x);
    unsigned secondSide = (unsigned )(rect.p.y - rect.q.y);

    for (int i = 0; i < secondSide; ++i) {
        for (int j = 0; j < firstSide; ++j) {
            if(     i != 0 && i != secondSide-1
               &&   j != 0 && j != firstSide-1 ) {
                std::cout << ' ';
            } else {
                std::cout << '*';
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

bool pointInRectangle(const Point& p, const Rectangle& rect) {
    return     (min(rect.p.x, rect.q.x) < p.x) && (p.x < max(rect.q.x, rect.q.x))
           &&  (min(rect.p.y, rect.q.y) < p.y) && (p.y < max(rect.q.y, rect.p.y));
}

//The algorithm works by ensuring there is no gap between
//any of the 4 sides of the rectangles
//Any gap means a collision does not exist.
//ref : https://developer.mozilla.org/kab/docs/Games/Techniques/2D_collision_detection
bool twoRectanglesIntersect(const Rectangle& first, const Rectangle& second) {

    Point firstTop, secondTop; //the closest to the right top points

    unsigned int fWidth, fHeight, //width and height of both rectangles
            sWidth, sHeight;

    firstTop.x = min(first.p.x, first.q.x);
    firstTop.y = min(first.p.y, first.q.y);
    fWidth = abs(first.p.x - first.q.x);
    fHeight = abs(first.p.y - first.q.y);

    secondTop.x = min(second.p.x, second.q.x);
    secondTop.y = min(second.p.y, second.q.y);
    sWidth = abs(second.p.x - second.q.x);
    sHeight = abs(second.p.y - second.q.y);

    // collision detected!
    return (firstTop.x <= secondTop.x + sWidth &&
            firstTop.x + fWidth >= secondTop.x &&
            firstTop.y <= secondTop.y + sHeight &&
            fHeight + firstTop.y >= secondTop.y);
}

