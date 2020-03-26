#pragma once
#include <fstream>

class Spacecraft
{
public:
    Spacecraft(int year = 0, const char* name = "");
    Spacecraft(std::ifstream& in);
    Spacecraft(const Spacecraft& other);
    Spacecraft& operator=(const Spacecraft& other);
    ~Spacecraft();

    void serialize(std::ofstream& out) const;

private:
    void copy(const Spacecraft& other);
    void clear();

    int year;
    char* name;
};
