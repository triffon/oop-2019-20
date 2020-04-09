#include <iostream>
#include <fstream>

#include "WashingMashine.h"

using std::ifstream;
using std::ofstream;

int main() {
    ifstream in("WashingMashines_in.txt");
    ofstream out("WashingMashines_out.txt");

    int n;
    WashingMachine* machines;
    WashingMachine bestMachine;

    in >> n;
    machines = new WashingMachine[n];

    for (int i = 0; i < n; i++) {
        in >> machines[i];
    }

    bestMachine = machines[0];

    for (int i = 1; i < n; i++) {
        if (machines[i] > bestMachine) {
            bestMachine = machines[i];
        }
    }

    out << bestMachine;

    delete[] machines;

    in.close();
    out.close();

    return 0;
}
