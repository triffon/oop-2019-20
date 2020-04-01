#include <iostream>
#include <fstream>
#include "Spacecraft.h"
#include "Vector.h"

bool readInput(const char* filePath, Vector& container);
bool storeSpacecrafts(const char* filePath, Vector& container);
bool getSpacecrafts(const char* filePath, Vector& container);

int main()
{
    Vector vec;
    if (!readInput("input.txt", vec)) {
        std::cout << "Couldn't open file input.txt for reading!" << std::endl;
        return -1;
    }

    if (!storeSpacecrafts("database.bin", vec)) {
        std::cout << "Couldn't open file database.bin for writing to store spacecrafts!" << std::endl;
        return -1;
    }

    Vector vecNew;
    if (!getSpacecrafts("database.bin", vecNew)) {
        std::cout << "Couldn't open file database.bin for reading to get spacecrafts!" << std::endl;
        return -1;
    }

    std::cout << "Original vector:" << std::endl << vec << std::endl << std::endl;
    std::cout << "Vector from the database:" << std::endl << vecNew << std::endl;

    return 0;
}


bool readInput(const char* filePath, Vector& container)
{
    const int MAX_BUFFER_LEN = 1024;

    std::ifstream inTxt(filePath);
    if (!inTxt)
        return false;

    // Reading the whole file
    while (!inTxt.eof()) {
        int year;
        char name[MAX_BUFFER_LEN];
        inTxt >> year;
        inTxt.ignore();
        inTxt.getline(name, MAX_BUFFER_LEN);
        container.push_back({year, name});
    }

    inTxt.close();
    return true;
}


bool storeSpacecrafts(const char* filePath, Vector& container)
{
    std::ofstream out(filePath, std::ios::binary);
    if (!out)
        return false;

    container.serialize(out);

    out.close();
    return true;
}


bool getSpacecrafts(const char* filePath, Vector& container)
{
    std::ifstream in(filePath, std::ios::binary);
    if (!in)
        return false;

    container.deserialize(in);

    in.close();
    return true;
}
