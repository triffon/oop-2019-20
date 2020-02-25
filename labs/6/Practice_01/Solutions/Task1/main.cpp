#include <iostream>
#include "Point.h"

int main() {
    Point p = {2, 2};
    Point q = {4, 4};

    Point t;
    enterPoint(t);

    std::cout << "Point p: "; printPoint(p);
    std::cout << "Point q: "; printPoint(q);
    std::cout << "Point t: "; printPoint(t);

    std::cout << "Distance from center to point p is: " << distanceFromCenter(p) << std::endl;
    std::cout << "Distance from center to point q is: " << distanceFromCenter(q) << std::endl;
    std::cout << "Distance from center to point t is: " << distanceFromCenter(t) << std::endl;

    std::cout << "Distance between p and q is: " << distance(p, q) << std::endl;
    std::cout << "Distance between q and t is: " << distance(q, t) << std::endl;
    std::cout << "Distance between t and p is: " << distance(t, p) << std::endl;
    
    return 0;
}