//
// Created by yasen on 2/29/20.
//

#ifndef STUDENTSANDTEACHERS_COURSE_H
#define STUDENTSANDTEACHERS_COURSE_H


#include <cstdlib>
#include "StudentList.h"

class Course {
public:
    Course();
    Course(const char* _name, size_t _capacity);

public:
    void enrolStudent(const Student& _student);
    void enrolStudents(const Student* list, size_t size);
    void printInformation() const;

    const char* getName() const;
private:
    char name[30];
    size_t capacity;
    StudentList students;


};


#endif //STUDENTSANDTEACHERS_COURSE_H
