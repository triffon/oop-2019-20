#include <cstring>
#include "Virus.h"

Virus::Virus(const char* name, double severity)
    : severity(severity)
    , name(new char[strlen(name) + 1])
{
    strcpy(this->name, name);
}


Virus::Virus(const Virus& other)
{
    copy(other);
}


Virus& Virus::operator=(const Virus& other)
{
    if (this != &other) {
        clear();
        copy(other);
    }
    return *this;
}


Virus::~Virus()
{
    clear();
}


void Virus::copy(const Virus& other)
{
    severity = other.severity;
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
}


void Virus::clear()
{
    delete[] name;
}


bool Virus::operator<(const Virus& other) const
{
    return severity < other.severity;
}


bool Virus::operator>=(const Virus& other) const
{
    return !(*this < other);
}


bool Virus::operator>(const Virus& other) const
{
    return severity > other.severity;
}


bool Virus::operator<=(const Virus& other) const
{
    return !(*this > other);
}


std::ostream& operator<<(std::ostream& out, const Virus& obj)
{
    return out << obj.getName() << " (" << obj.getSeverity() << ")";
}


void Virus::setName(const char* newName)
{
    if (newName != nullptr) {
        delete[] name;
        name = new char[strlen(newName) + 1];
        strcpy(name, newName);
    }
}


void Virus::setSeverity(double newSeverity)
{
    severity = newSeverity;
}
