#include <iostream>

#include "set.cpp"
#include "order.cpp"
#include "point.hpp"

using std::cout;
using std::endl;

int main() {
    Set<Point> hashSet;
    Order<Point> treeSet;
    Point p1(3,4);
    Point p2(1,6);
    Point p3(2,1);
    Point p5(2,1);
    Point p6(2,4);
    Point p4(2,1);
    Point p7(2,2);

    hashSet.add(p1);
    hashSet.add(p2);
    hashSet.add(p3);
    hashSet.add(p4);
    hashSet.add(p5);
    hashSet.add(p6);
    hashSet.add(p7);

    for(int i=0, sze = hashSet.size(); i<sze; ++i) {
        cout << hashSet[i] << endl;
    }

    cout << "---------------\n";

    treeSet.add(p1);
    treeSet.add(p2);
    treeSet.add(p3);
    treeSet.add(p4);
    treeSet.add(p5);
    treeSet.add(p6);
    treeSet.add(p7);

    for(int i=0, sze = treeSet.size(); i<sze; ++i) {
        cout << treeSet[i] << endl;
    }

    return 0;
}
