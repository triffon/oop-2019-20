#include <iostream>

struct Point {
    double x, y;
} p, q;
Point r;

struct Student {
    char name[30];
    int fn;
    double grade;
};

int main(int, char**) {
    std::cout << "sizeof(Point) = " << sizeof(Point) << std::endl;
    std::cout << "sizeof(Student) = " << sizeof(Student) << std::endl;
    Point p = { 1.2, 3.4 }, q;
    q = p;
    Student s = { "Иван Колев", 40000, 5.75 };
    // !!! q = s;
    // !!! s = q;
    // !!! std::cout << s;
    // !!! std::cin >> s;
    return 0;
}
