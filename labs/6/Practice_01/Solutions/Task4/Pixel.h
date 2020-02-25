//
// Created by yasen on 2/22/20.
//

#ifndef TASK4_PIXEL_H
#define TASK4_PIXEL_H

enum Color {
    Red,
    Green,
    Blue,
    Yellow,
    Purple,
};

struct Pixel {
    unsigned short red;
    unsigned short green;
    unsigned short blue;
};

void setColor(Pixel&, Color);
void printPixel(const Pixel&);


#endif //TASK4_PIXEL_H
