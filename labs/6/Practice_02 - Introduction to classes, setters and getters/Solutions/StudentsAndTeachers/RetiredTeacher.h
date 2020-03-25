//
// Created by yasen on 2/29/20.
//

#ifndef STUDENTSANDTEACHERS_RETIREDTEACHER_H
#define STUDENTSANDTEACHERS_RETIREDTEACHER_H


#include "Course.h"

class RetiredTeacher {
public:
    RetiredTeacher(const char* _name, unsigned short _teachingExperience);

public:
    void add(const Course& course);
    bool isTeachingCourse(const char* courseName) const;
    bool isTeachingCourse(const Course& _course) const;

private:
    char name[30];
    unsigned short teachingExperience;
    size_t countCourses;
    Course courses[MAX_CAPACITY];
};


#endif //STUDENTSANDTEACHERS_RETIREDTEACHER_H
