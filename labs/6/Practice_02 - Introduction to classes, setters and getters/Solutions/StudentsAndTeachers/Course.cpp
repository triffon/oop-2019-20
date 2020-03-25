//
// Created by yasen on 2/29/20.
//

#include <cstring>
#include <iostream>
#include "Course.h"

Course::Course() : students(200) {
    strcpy(name, "Unknown");
    capacity = 200;
}

Course::Course(const char *_name, size_t _capacity) : students(_capacity) {
    strcpy(name, _name);
    capacity = students.getCapacity();
}

void Course::enrolStudent(const Student& _student) {
    students.add(_student);
}

void Course::enrolStudents(const Student* list, size_t size) {
    for (int i = 0; i < size; ++i) {
        students.add(list[i]);
    }
}

void Course::printInformation() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Students in the course are: " << std::endl;
    students.print();
}

const char* Course::getName() const {
    return name;
}

