#pragma once
#include <string>
#include <vector>
#include "Person.hpp"
#include "Subject.hpp"

class Student : public Person
{
    using string      = std::string;
    using container_t = std::vector<Subject>;

public:
    Student(const string& name = "unnamed", size_t age = 0, size_t fNum = 0, const string& specialty = "nothing");
    Student(const Person& person, size_t fNum = 0, const string& specialty = "nothing");

    void   print() const;
    size_t learn(const Subject& subj);

    inline void setSpecialty(const string& spec) { m_specialty = spec; }
    inline size_t getFacultyNum() { return m_fNum; }

private:
    int getSubjectIndex(const string& subjName) const;

    size_t      m_fNum;
    size_t      m_learnLvl;
    string      m_specialty;
    container_t m_subjects;
};