#include <iostream>
#include "Teacher.hpp"

using std::string;
using std::cout;

const float  TEACH_SKILL_FACTOR_INCR = 0.5;
const size_t MAX_START_SKILL_LEVEL   = 30;
const size_t MIN_START_SKILL_LEVEL   = 10;

Teacher::Teacher(const string& name, size_t age, const string& subj)
    : Person(name, age)
    , m_subject({subj, MIN_START_SKILL_LEVEL + rand() % (MAX_START_SKILL_LEVEL + 1)})
{}


Teacher::Teacher(const Person& person, const string& subj)
    : Teacher(person.getName(), person.getAge(), subj)
{}


void Teacher::print() const
{
    Person::print();
    cout << " and is teaching " << m_subject.name << " with a skill level of " << m_subject.skill;
}


void Teacher::teach(Student& st)
{
    m_subject.skill += st.learn(m_subject) * TEACH_SKILL_FACTOR_INCR;
}
