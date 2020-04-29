#include <iostream>
#include "Student.hpp"

using std::string;
using std::cout;
using std::endl;

const size_t MAX_LEARN_LVL      = 100;
const size_t MAX_START_LVL      = 20;
const float  LEARN_FACTOR       = 0.6;
const float  LEARN_FACTOR_INCR  = 0.1;

Student::Student(const string& name, size_t age, size_t fNum, const string& specialty)
    : Person(name, age)
    , m_fNum(fNum)
    , m_learnLvl(rand() % MAX_START_LVL)
    , m_specialty(specialty)
{}


Student::Student(const Person& person, size_t fNum, const string& specialty)
    : Student(person.getName(), person.getAge(), fNum, specialty)
{}


void Student::print() const
{
    Person::print();
    cout << " and is studying " << m_specialty << ", FN: " << m_fNum << endl;

    cout << " - Student's subjects - ";
    for (size_t i = 0; i < m_subjects.size(); i++)
        cout << endl << "  " << m_subjects[i].name << ", lvl: " << m_subjects[i].skill;
}


size_t Student::learn(const Subject& subj)
{
    int index = getSubjectIndex(subj.name);
    size_t learntSkill = subj.skill * LEARN_FACTOR;

    if (index == -1)
        m_subjects.push_back({subj.name, learntSkill});
    else
        m_subjects[index].skill += learntSkill;

    m_learnLvl += learntSkill * LEARN_FACTOR_INCR;
    if (m_learnLvl > MAX_LEARN_LVL)
        m_learnLvl = MAX_LEARN_LVL;

    cout << m_name << " just learned " << learntSkill << "x " << subj.name << endl;

    return m_learnLvl;
}


int Student::getSubjectIndex(const string& subjName) const
{
    for (size_t i = 0; i < m_subjects.size(); i++)
        if (subjName.compare(m_subjects[i].name) == 0)
            return i;

    return -1;
}
