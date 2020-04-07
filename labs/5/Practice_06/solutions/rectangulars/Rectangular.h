#include <iostream>
#pragma once

class Rectangular {
    int width, height;

public:
    Rectangular();
    Rectangular(int w, int h);
    bool operator>(Rectangular const& rect);
    Rectangular& operator=(Rectangular const& rect);
    int getArea();
};
