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

    inline const char* getName() const { return name; }
    inline int getYear() const { return year; }

private:
    void copy(const Spacecraft& other);
    void clear();

    int year;
    char* name;
};

std::ostream& operator<<(std::ostream& out, const Spacecraft& obj);
