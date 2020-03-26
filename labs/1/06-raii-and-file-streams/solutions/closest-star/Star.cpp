#include <iostream>
#include <cmath>
#include <iomanip>
#include "Star.h"

void readStarFromFile(std::ifstream& in, Star& obj)
{
    in >> obj.x >> obj.y >> obj.z;
}


int readStarsFromFile(const char* fileName, Star* arr)
{
    std::ifstream in(fileName);
    if (!in) {
        std::cout << "Couldn't open file for reading!" << std::endl;
        return -1;
    }

    int numOfStars;
    in >> numOfStars;

    for (int i = 0; i < numOfStars; i++)
        readStarFromFile(in, arr[i]);

    in.close();

    return numOfStars;
}


int getClosestStarIndex(const Star* arr, int size, double& closestDistance)
{
    int closestIndex = 0;
    closestDistance = distance(arr[0]);
    for (int i = 1; i < size; i++)
    {
        double currDist = distance(arr[i]);
        if (currDist < closestDistance) {
            closestDistance = currDist;
            closestIndex = i;
        }
    }
    return closestIndex;
}


double distance(const Star& star)
{
    return sqrt((star.x * star.x) + (star.y * star.y) + (star.z * star.z));
}


bool writeResultToFile(const char* fileName, const Star& star, double dist)
{
    std::ofstream out(fileName, std::ios::app);
    if (!out) {
        std::cout << "Couldn't open file for writing!" << std::endl;
        return false;
    }

    out << std::endl << std::endl << "The closest star to us is located at ("
        << star.x << ", " << star.y << ", " << star.z << ") that is "
        << std::setprecision(2) << std::fixed << dist << " lightyears away.";

    out.close();
    return true;
}
