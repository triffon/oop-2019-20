//
// Created by yasen on 2/22/20.
//



#include <iostream>
#include "Pixel.h"

void setColor(Pixel& pixel, Color color) {
    if(color == Color::Red) {
        pixel.red = 255;
        pixel.green = 0;
        pixel.blue = 0;
    } else if (color == Color::Green) {
        pixel.red = 0;
        pixel.green = 255;
        pixel.blue = 0;
    } else if (color == Color::Blue) {
        pixel.red = 0;
        pixel.green = 0;
        pixel.blue = 255;
    } else if (color == Color::Purple) {
        pixel.red = 128;
        pixel.green = 0;
        pixel.blue = 128;
    } else if (color == Color::Yellow) {
        pixel.red = 255;
        pixel.green = 255;
        pixel.blue = 0;
    }
}


void printPixel(const Pixel& pixel) {
    std::cout << "( " << pixel.red << ", " << pixel.green << ", " << pixel.blue << " ) ";
}

