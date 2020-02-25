#include <iostream>
#include "Screen.h"

int main() {
    Screen screen, screen1;
    enterScreen(screen);
    enterScreen(screen1);

    setColor(screen, Red);
    printScreen(screen);

    setColor(screen1, Yellow);
    printScreen(screen1);

    if(compareByInches(screen, screen1)) {
        std::cout << "First screen has less inches then second" << std::endl;
    } else {
        std::cout << "First screen has greater inches then second" << std::endl;
    }

    ecoScreen(screen);
    printScreen(screen);

    return 0;
}