#include <iostream>
#include "Eatable.h"

using std::cout;
using std::endl;

Eatable::Eatable(Taste taste) {
    this->taste = taste;
}

void Eatable::print() {
    cout << "Taste: ";
    switch(taste) {
        case SWEET: cout << "SWEET";
            break;
        case SOUR: cout << "SOUR";
            break;
        case SALT: cout << "SALT";
            break;
        case BITTER: cout << "BITTER";
            break;
        case SAVORY: cout << "SAVORY";
            break;
    }
    cout << endl;
}

