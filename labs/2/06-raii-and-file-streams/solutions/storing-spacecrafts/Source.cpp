#include <iostream>
#include <fstream>
#include "Spacecraft.h"
#include "Vector.h"

const int MAX_BUFFER_LEN = 1024;

int main()
{
    Vector vec;
    std::ifstream inTxt("input.txt");
    if (!inTxt) {
        std::cout << "Couldn't open file for reading!" << std::endl;
        return -1;
    }

    // Reading the whole file
    while (!inTxt.eof()) {
        int year;
        char name[MAX_BUFFER_LEN];
        inTxt >> year;
        inTxt.ignore();
        inTxt.getline(name, MAX_BUFFER_LEN);
        vec.push_back({year, name});
    }

    inTxt.close();

    // Homework:
    // 1) Add operator<< to Spacecraft
    // 2) Add serialize method and constructor(std::ifstream&) to Vector
    // 3) Finish the solution

    return 0;
}
