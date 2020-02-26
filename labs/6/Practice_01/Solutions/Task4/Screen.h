//
// Created by yasen on 2/22/20.
//

#ifndef TASK4_SCREEN_H
#define TASK4_SCREEN_H

#include "Pixel.h"

struct Screen {
    Pixel pixels[16];
    double inches;
    unsigned short brightness;
};

void enterScreen(Screen&);
void printScreen(const Screen&);
void setColor(Screen&, Color);
bool compareByInches(const Screen&, const Screen&);
void ecoScreen(Screen&);

#endif //TASK4_SCREEN_H
