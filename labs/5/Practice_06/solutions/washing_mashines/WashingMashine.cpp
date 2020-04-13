#include <cstring>
#include <fstream>

#include "WashingMashine.h"

using std::ostream;
using std::istream;
using std::endl;

WashingMachine::WashingMachine() {
    strcpy(brand, "\0");
    strcpy(model, "\0");
    acceptableWeight = 0;
    energy = 0.0;
    water = 0;
}

bool WashingMachine::operator>(const WashingMachine& wm) {
    if (acceptableWeight > wm.acceptableWeight) return true;
    else if (energy < wm.energy) return true;
    else return water < wm.water;
}

WashingMachine& WashingMachine::operator=(const WashingMachine& wm) {
    strcpy(brand, wm.brand);
    strcpy(model, wm.model);
    acceptableWeight = wm.acceptableWeight;
    energy = wm.energy;
    water = wm.water;

    return *this;
}

ostream& operator<<(ostream& o, WashingMachine const& wm){
    o << wm.brand << " " << wm.model << endl;
    return o;
}

istream& operator>>(istream& in, WashingMachine& wm) {
    in.ignore();
    in.getline(wm.brand, MAX_STRING);
    in.getline(wm.model, MAX_STRING);
    in >> wm.acceptableWeight;
    in >> wm.energy;
    in >> wm.water;
    return in;
}
