#pragma once
#include "Person.hpp"
#include "Student.hpp"
#include "Subject.hpp"

class Teacher : public Person
{
    using string = std::string;

public:
    Teacher(const string& name = "unnamed", size_t age = 0, const string& subj = "nothing");
    Teacher(const Person& person, const string& subj = "nothing");

    void print() const;
    void teach(Student& st);

    inline string getSubject() const { return m_subject.name; }

private:
    Subject m_subject;
};
