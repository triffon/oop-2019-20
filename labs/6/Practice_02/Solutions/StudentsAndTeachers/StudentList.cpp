//
// Created by yasen on 2/29/20.
//

#include <iostream>
#include <cstring>
#include "StudentList.h"

StudentList::StudentList(size_t _capacity) {
    if(_capacity > MAX_CAPACITY) {
        capacity = MAX_CAPACITY;
    } else {
        capacity = _capacity;
    }
    size = 0;
}

void StudentList::add(const Student& _student) {
    if(size < capacity) {
        if(!this->existInTheList(_student.getFacultyNumber())) {
            students[size] = _student;
            ++size;
            std::cout << "Added student: "; _student.printInformation();
        }
    }
}

void StudentList::remove(unsigned _FN) {
    for (int i = 0; i < size; ++i) {
        if(students[i].getFacultyNumber() == _FN) {
            for (int j = i; j < size-1; ++j) {
                students[j] = students[i];
            }
            --size;
            break;
        }
    }
}

void StudentList::remove(const Student& _student) {
    for (int i = 0; i < size; ++i) {
        if (this->isTheSameStudents(students[i], _student)) {
            for (int j = i; j < size - 1; ++j) {
                students[j] = students[i];
            }
            --size;
            break;
        }
    }
}

bool StudentList::contains(unsigned _FN) {
    return this->existInTheList(_FN);
}

bool StudentList::contains(const Student& _student) {
    return this->existInTheList(_student);
}

void StudentList::print() const {
    for (int i = 0; i < size; ++i) {
        students[i].printInformation();
    }
}

size_t StudentList::getCapacity() const {
    return capacity;
}

bool StudentList::existInTheList(unsigned FN) const {
    bool result = false;

    for (int i = 0; i < size; ++i) {
        if(students[i].getFacultyNumber() == FN) {
            result = true;
            break;
        }
    }
    return result;
}

bool StudentList::existInTheList(const Student& _student) const {
    bool result = false;
    for (int i = 0; i < size; ++i) {
        if(this->isTheSameStudents(students[i], _student)) {
            result = true;
            break;
        }
    }
    return result;
}

bool StudentList::isTheSameStudents(const Student& s1, const Student& s2) const {
    return      s1.getFacultyNumber() == s2.getFacultyNumber()
            &&  strcmp(s1.getName(), s2.getName()) == 0
            &&  strcmp(s1.getMajor(), s2.getMajor()) == 0
            &&  s1.getGroup() == s2.getGroup();
}

