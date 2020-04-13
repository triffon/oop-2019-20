#include <cstring>
#include "Spacecraft.h"


Spacecraft::Spacecraft(int year, const char* name)
    : year(year)
    , name(new char[strlen(name) + 1])
{
    strcpy(this->name, name);
}


Spacecraft::Spacecraft(std::ifstream& in)
{
    in.read((char*) &year, sizeof(year));

    int len;
    in.read((char*) &len, sizeof(len));
    name = new char[len];
    in.read(name, len);
}


Spacecraft::Spacecraft(const Spacecraft& other)
{
    copy(other);
}


Spacecraft& Spacecraft::operator=(const Spacecraft& other)
{
    if (this != &other) {
        clear();
        copy(other);
    }
    return *this;
}


Spacecraft::~Spacecraft()
{
    clear();
}


void Spacecraft::copy(const Spacecraft& other)
{
    this->year = other.year;
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);
}


void Spacecraft::clear()
{
    delete[] name;
    name = nullptr;
}


void Spacecraft::serialize(std::ofstream& out) const
{
    out.write((const char*) &year, sizeof(year));

    int len = strlen(name) + 1;
    out.write((const char*) &len, sizeof(len));
    out.write((const char*) name, len);
}


std::ostream& operator<<(std::ostream& out, const Spacecraft& obj)
{
    return out << obj.getYear() << " " << obj.getName();
}
