//
// Created by yasen on 2/29/20.
//

#include <cstring>
#include "RetiredTeacher.h"

RetiredTeacher::RetiredTeacher(const char* _name, unsigned short _teachingExperience) {
    strcpy(name, _name);
    teachingExperience = _teachingExperience;
    countCourses = 0;
}

void RetiredTeacher::add(const Course& course) {
    courses[countCourses] = course;
    countCourses++;
}

bool RetiredTeacher::isTeachingCourse(const char* courseName) const {
    bool result = false;

    for (int i = 0; i < countCourses; ++i) {
        if( strcmp(courses[i].getName(), courseName) == 0) {
            result = true;
            break;
        }
    }
    return result;
}

bool RetiredTeacher::isTeachingCourse(const Course& _course) const {
    return this->isTeachingCourse(_course.getName());
}
