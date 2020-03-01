//
// Created by yasen on 2/29/20.
//

#ifndef STUDENTSANDTEACHERS_STUDENTLIST_H
#define STUDENTSANDTEACHERS_STUDENTLIST_H


#include <cstdlib>
#include "Student.h"

#define MAX_CAPACITY (200)

class StudentList {
public:
    StudentList(size_t _capacity);
    void add(const Student& _student);
    void remove(unsigned _FN);
    void remove(const Student& _student);
    bool contains(unsigned _FN);
    bool contains(const Student& _student);
    void print() const;
    size_t getCapacity() const;

private:
    bool existInTheList(unsigned FN) const;
    bool existInTheList(const Student& _student) const;
    bool isTheSameStudents(const Student& s1, const Student& s2) const;

private:
    Student students[MAX_CAPACITY];
    size_t size;
    size_t capacity;
};


#endif //STUDENTSANDTEACHERS_STUDENTLIST_H
