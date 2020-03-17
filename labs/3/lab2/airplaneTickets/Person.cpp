//
// Created by tony on 17.03.20 г..
//
#include <string.h>
#include "Person.h"

const char *Person::getFirstName() const
{
    return firstName;
}

const char *Person::getSurname() const
{
    return surname;
}

const char *Person::getFamilyName() const
{
    return familyName;
}

int Person::getEgn() const
{
    return egn;
}

int Person::getAge() const
{
    return age;
}

void Person::setFirstName(const char *firstName)
{
    strcpy(this->firstName, firstName);
}

void Person::setSurname(const char *surname)
{
    strcpy(this->surname, surname);
}

void Person::setFamilyName(const char *familyName)
{
    strcpy(this->familyName, familyName);
}

void Person::setEgn(int egn)
{
    this->egn = egn;
}

void Person::setAge(int age)
{
    this->age = age;
}
