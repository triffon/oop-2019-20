#include <iostream>
#include "Rectangular.h"

Rectangular::Rectangular() {
    width = 0;
    height = 0;
}

Rectangular::Rectangular(int w, int h) {
    width = w;
    height = h;
}

Rectangular& Rectangular::operator=(Rectangular const& rect) {
    width = rect.width;
    height = rect.height;
    return *this;
}

bool Rectangular::operator>(Rectangular const& rect) {
    return width * height > rect.width * rect.height;
}

int Rectangular::getArea(){
    return width * height;
}
