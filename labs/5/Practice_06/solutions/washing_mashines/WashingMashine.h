#pragma once

#include <fstream>

#define MAX_STRING 32

using std::ostream;
using std::istream;

class WashingMachine {
    char brand[MAX_STRING];
    char model[MAX_STRING];
    int acceptableWeight;
    double energy;
    int water;

public:
    WashingMachine();
    friend istream& operator>>(istream& in, WashingMachine& wm);
    bool operator>(const WashingMachine& wm);
    WashingMachine& operator=(const WashingMachine& wm);
    friend ostream& operator<<(ostream& o, const WashingMachine& wm);
};
