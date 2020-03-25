//
// Created by yasen on 2/22/20.
//

#include <iostream>
#include "Screen.h"

void enterScreen(Screen& screen) {
    std::cout << "Enter screen parameters: " << std::endl;
    std::cout << "Enter inches:" << std::endl;
    std::cin >> screen.inches;
    std::cout << "Enter brightness:" << std::endl;
    std::cin >> screen.brightness;
}

void printScreen(const Screen& screen) {
    for (int i = 0; i < 16; ++i) {
        printPixel(screen.pixels[i]);
        if ( ((i+1)%4) == 0 ) {
            std::cout << std::endl;
        }
    }
    std::cout << "\nInches: " << screen.inches;
    std::cout << "\nBrightness: " << screen.brightness << std::endl;
}

void setColor(Screen& screen, Color color) {
    for (int i = 0; i < 16; ++i) {
        setColor(screen.pixels[i], color);
    }
}

bool compareByInches(const Screen& screen1, const Screen& screen2) {
    return screen1.inches < screen2.inches;
}

void ecoScreen(Screen& screen) {
    if (screen.brightness >= 20) {
        screen.brightness -= 20;
    }
}

