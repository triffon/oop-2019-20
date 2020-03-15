#pragma once
#include <iostream>

class Virus
{
public:
    Virus(const char* name = "", double severity = 0);
    Virus(const Virus& other);
    Virus& operator=(const Virus& other);
    ~Virus();

    bool operator<(const Virus& other) const;
    bool operator>=(const Virus& other) const;
    bool operator>(const Virus& other) const;
    bool operator<=(const Virus& other) const;

    const char* getName() const { return name; }
    void setName(const char* newName);
    double getSeverity() const { return severity; }
    void setSeverity(double newSeverity);

private:

    void copy(const Virus& other);
    void clear();

    double severity;
    char* name;
};

std::ostream& operator<<(std::ostream& out, const Virus& obj);
