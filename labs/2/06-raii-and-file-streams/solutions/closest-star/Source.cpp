#include <iostream>
#include <fstream>
#include "Star.h"

const int MAX_STARS = 64;
const int MAX_FILENAME_LEN = 32;

int main()
{
    Star arr[MAX_STARS];

    char fileName[MAX_FILENAME_LEN];
    std::cout << "Enter file path: ";
    std::cin >> fileName;

    int numOfStars = readStarsFromFile(fileName, arr);

    if (numOfStars == -1)
        return -1;

    double closestDistance; // output parameter of getClosestStarIndex
    int closestIndex = getClosestStarIndex(arr, numOfStars, closestDistance);

    if (writeResultToFile(fileName, arr[closestIndex], closestDistance))
        std::cout << "Successfully appended result!" << std::endl;

    return 0;
}
