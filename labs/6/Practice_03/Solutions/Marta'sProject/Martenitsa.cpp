//
// Created by yasen on 3/8/20.
//

#include <cstring>
#include <iostream>
#include "Martenitsa.h"

#define MAX_BUFF (1024)


Martenitsa::Martenitsa() {
    init("Unknown", "Nothing", 0, 0);
}


Martenitsa::Martenitsa(const char* name, const char* wish, size_t length, size_t countBeads) {
    init(name, wish, length, countBeads);
}

Martenitsa::Martenitsa(const Martenitsa& other) {
    if(this != &other) {
        copyFrom(other);
    }
}

Martenitsa& Martenitsa::operator=(const Martenitsa& other) {
    if(this != &other) {
        clean();
        copyFrom(other);
    }
    return *this;
}

Martenitsa::~Martenitsa() {
    clean();
}

//-------------------------------------------------------------

void Martenitsa::print() const {
    std::cout << "\nMartentsa information:" << std::endl;

    std::cout << "Student name: " << fStudentName << std::endl;
    std::cout << "Marta's wish: " << fWish << std::endl;
    std::cout << "Martenitsa length: " << fLength << std::endl;
    std::cout << "Numbers of beads: " << fCountBeads << std::endl;
    std::cout << std::endl;
}

void Martenitsa::readFromConsole() {
    char name[MAX_BUFF];
    char wish[MAX_BUFF];
    size_t length;
    size_t countBeads;

    std::cout << "Enter martenitsa information!" << std::endl;
    std::cin.ignore(MAX_BUFF, '\n');
    std::cout << "Student name: " << std::endl;
    std::cin.getline(name, MAX_BUFF);
    std::cout << "Marta's wish: " << std::endl;
    std::cin.getline(wish, MAX_BUFF);
    std::cout << "Martenitsa length: " << std::endl;
    std::cin >> length;
    std::cout << "Numbers of beads: " << std::endl;
    std::cin >> countBeads;

    init(name, wish, length, countBeads);
}


bool Martenitsa::lessThen(const Martenitsa& other) const {
    bool result = false;
    if (fLength < other.fLength) {
        result = true;
    }
    else if (fLength == other.fLength) {
        result = fCountBeads < other.fCountBeads;
    } else {
        result = false;
    }
    return result;
}

bool Martenitsa::graterThen(const Martenitsa& other) const {
    return !this->lessThen(other);
}

//---------------------------------------------------------------

void Martenitsa::copyFrom(const Martenitsa& other) {
    init(other.fStudentName, other.fWish, other.fLength, other.fCountBeads);
}

void Martenitsa::clean() {
    delete[] fStudentName;
    delete[] fWish;
}

void Martenitsa::init(const char* name, const char* wish, size_t length, size_t countBeads) {
    fStudentName    = new char[strlen(name) + 1];
    fWish           = new char[strlen(wish) + 1];
    strcpy(fStudentName, name);
    strcpy(fWish, wish);

    fLength     = length;
    fCountBeads = countBeads;
}


