#pragma once
#include <vector>
#include "Teacher.hpp"
#include "Student.hpp"

class University
{
    using teachersVec = std::vector<Teacher>;
    using studentsVec = std::vector<Student>;
    using string      = std::string;

public:
    University();
    void run();

private:
    size_t getNextFN();
    int    getTeacherIndex(const string& name) const;
    int    getStudentIndex(const string& name) const;

private:
    static const size_t STARTING_FAC_NUM;

    size_t      currFacNum;
    teachersVec m_teachers;
    studentsVec m_students;
};
