//
// Created by yasen on 2/29/20.
//

#include <cstring>
#include <iostream>
#include "Student.h"

Student::Student() {
    facultyNumber = 0;
    strcpy(name, "Unknown");
    strcpy(major, "Unknown");
    group = 0;
}

Student::Student(unsigned _facultyNumber, const char* _name, const char* _major, unsigned short _group) {
    facultyNumber = (this->isValidFN(_facultyNumber) ? _facultyNumber : 0);
    strcpy(name, _name);
    strcpy(major, (this->isValidMajor(_major) ? _major : "Major Not Chosen" ));
    group = (this->isValidGroup(_group) ? _group : 0);
}

unsigned Student::getFacultyNumber() const {
    return facultyNumber;
}

const char* Student::getName() const {
    return name;
}

const char* Student::getMajor() const {
    return major;
}

void Student::setMajor(const char* newMajor) {
    strcpy(major, (this->isValidMajor(newMajor) ? newMajor : "Major Not Chosen" ));
}

unsigned short Student::getGroup() const {
    return group;
}

void Student::setGroup(unsigned short newGroup) {
    group = (this->isValidGroup(newGroup) ? newGroup : 0);
}

void Student::printInformation() const {
    std::cout << facultyNumber << ", " << name << ", " << major << ", group " << group << std::endl;
}

void Student::readFromConsole() {
    std::cin >> facultyNumber;
    std::cin.getline(name, 50);
    char majorBuffer[33];
    std::cin.getline(majorBuffer, 32);
    strcpy(major, (this->isValidMajor(majorBuffer) ? majorBuffer : "Major Not Chosen"));
}

bool Student::isValidFN(unsigned FN) const {
    return 10000 <= FN && FN < 100000;
}

bool Student::isValidGroup(unsigned short _group) const {
    return 1 <= _group && _group <= 8;
}

bool Student::isValidMajor(const char* _major) const {
    bool result = false;
    for (int i = 0; i < countMajors; ++i) {
        if(strcmp(majors[i], _major) == 0) {
            result = true;
            break;
        }
    }
    return result;
}
