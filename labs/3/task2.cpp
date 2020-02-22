#include <iostream>
#include <cmath>

using namespace std;
struct Point{
    int x;
    int y;
    Point(int x, int y){
        this->x = x;
        this->y = y;
    }
};

int getDist(Point first, Point second){
    return sqrt((first.x - second.x)*(first.x - second.x) + (first.y - second.y)*(first.y - second.y));
    //Намираме разстоянието между 2те точки
}

bool checkIfRectangle(Point a, Point b, Point c, Point d){
    int ab = getDist(a, b);
    int bc = getDist(b, c);
    int cd = getDist(c, d);
    int da = getDist(d, a);
    return ab == cd && bc == da;
}


int main(){
    int x, y;
    cout << "Enter the coordinates of point A. The values should be between 1 and 100. Enter x: ";
    cin >> x;
    cout << "Enter y: ";
    cin >> y;
    Point a(x, y);
    cout << "Enter the coordinates of point B. The values should be between 1 and 100. Enter x: ";
    cin >> x;
    cout << "Enter y: ";
    cin >> y;
    Point b(x, y);
    cout << "Enter the coordinates of point C. The values should be between 1 and 100. Enter x: ";
    cin >> x;
    cout << "Enter y: ";
    cin >> y;
    Point c(x, y);
    cout << "Enter the coordinates of point D. The values should be between 1 and 100. Enter x: ";
    cin >> x;
    cout << "Enter y: ";
    cin >> y;
    Point d(x, y);

    cout << boolalpha << checkIfRectangle(a, b, c, d);



    return 0;
}
