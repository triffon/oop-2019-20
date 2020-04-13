#include <iostream>
#include <fstream>
#include "Rectangular.h"

using std::ifstream;
using std::ofstream;

int main() {
    int n, w, h;

    Rectangular maxAreaRect, rect;

    ifstream inputFile("Rectangulars_in.txt");
    ofstream outputFile("Rectangulars_out.txt");

    inputFile >> n;

    for (int i = 0; i < n; i++) {
        inputFile >> w >> h;
        rect = *(new Rectangular(w, h));
        if (rect > maxAreaRect || i == 0) {
            maxAreaRect = rect;
        }
    }

    outputFile << maxAreaRect.getArea();

    inputFile.close();
    outputFile.close();

    return 0;
}
