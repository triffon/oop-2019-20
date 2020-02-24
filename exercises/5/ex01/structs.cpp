/*
    Задача: Да се напише функция, която намира разстоянието между две точки в равнината.
    Да се напише програма, която прочита от стандартния вход n на брой точки в равнината 
    и извежда най-голямото разстояние между две от тях.
*/

#include <cmath>
#include <iostream>

struct point {
    double x, y;
};

int n;
point * points;

double calcDistance(point &p, point &q) {
    return hypot(q.x - p.x, q.y - p.y);
}

int main() {
    std::cin >> n;

    points = new point[n];

    for (int i = 0; i < n; ++i) {
        std::cin >> points[i].x >> points[i].y;
    }

    double maxDistance = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            double distance = calcDistance(points[i], points[j]);
            if (distance > maxDistance) {
                maxDistance = distance;
            }
        }
    }

    std::cout << maxDistance << std::endl;

    delete[] points;

    return 0;
}