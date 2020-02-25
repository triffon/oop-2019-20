/*
    Задача: Да се напише функция, която намира разстоянието между две точки в равнината.
    Да се напише програма, която прочита от стандартния вход n на брой точки в равнината 
    и извежда най-голямото разстояние между две от тях.
*/

#include <cmath>
#include <iostream>

int n;
double * x, * y; // ще използваме два отделни масива за координатите на точките

double calcDistance(double x1, double y1, double x2, double y2) {
    return hypot(x2 - x1, y2 - y1);
}

int main() {
    std::cin >> n;

    x = new double[n];
    y = new double[n];

    for (int i = 0; i < n; ++i) {
        std::cin >> x[i] >> y[i];
    }

    double maxDistance = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            double distance = calcDistance(x[i], y[i], x[j], y[j]);
            if (distance > maxDistance) {
                maxDistance = distance;
            }
        }
    }

    std::cout << maxDistance << std::endl;

    delete[] x;
    delete[] y;

    return 0;
}