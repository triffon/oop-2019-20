#include <iostream>
#include <vector>

using namespace std;

void printPoint(pair<double, double> p) {
    cout << "(" << p.first << ", " << p.second << ") ";
}

bool areOnOneLine(pair<double, double> p1,
                  pair<double, double> p2,
                  pair<double, double> p3) {
    return (p1.first * (p2.second - p3.second)
            - p1.second * (p2.first - p3.first)
            + p2.first * p3.second - p2.second * p3.first) == 0;
}

int main() {
    int n;
    double x, y;
    vector<pair<double, double>> points;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        points.push_back(make_pair(x, y));
    }

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            for(int k = j+1; k < n; k++) {
                if (areOnOneLine(points[i], points[j], points[k])) {
                    printPoint(points[i]);
                    printPoint(points[j]);
                    printPoint(points[k]);
                    cout << endl;
                }
            }
        }
    }

    return 0;
}
