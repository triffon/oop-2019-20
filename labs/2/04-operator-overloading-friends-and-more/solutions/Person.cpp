#include <cstring>
#include "Person.h"

Person::Person(const char* name, int age)
    : age(age)
{
    strcpy(this->name, name);
}


Person::Person(const Person& other)
{
    copy(other);
}


Person& Person::operator=(const Person& other)
{
    if (this != &other) {
        // Since there isn't any dynamically allocated
        // memory, we don't need to delete anything,
        // we can just copy every data member
        copy(other);
    }
    return *this;
}


void Person::copy(const Person& other)
{
    this->age = other.age;
    // Since we have defined operator= for our
    // class Vector, we can easily copy it
    this->viruses = other.viruses;
    strcpy(this->name, other.name);
}


void Person::infect(const Virus& virus)
{
    for (int i = 0; i < viruses.size(); i++) {
        // Search for a virus with the same name
        if (strcmp(viruses[i].getName(), virus.getName()) == 0) {
            // If found change its severity and end the function
            viruses[i].setSeverity(viruses[i].getSeverity() + virus.getSeverity());
            return;
        }
    }

    // If no such virus was found, we add it to the vector
    viruses += virus;
}
