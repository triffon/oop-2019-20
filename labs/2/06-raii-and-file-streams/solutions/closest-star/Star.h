#pragma once
#include <fstream>

struct Star {
    double x;
    double y;
    double z;
};

// Reads Star obj from filestream in
void readStarFromFile(std::ifstream& in, Star& obj);

// Reads the whole file with name fileName and
// loads all the stars in the given array
// Returns the number of read stars
// or -1 if the function failed
int readStarsFromFile(const char* fileName, Star* arr);

// Returns the index of the closest star from the array
// closestDistance is an output parameter
int getClosestStarIndex(const Star* arr, int size, double& closestDistance);

// Returns the distance from the center to the given star
double distance(const Star& star);

// Writes the output message with the given star and distance to the file
// Returns true if the function was executed successfully
bool writeResultToFile(const char* fileName, const Star& star, double dist);
