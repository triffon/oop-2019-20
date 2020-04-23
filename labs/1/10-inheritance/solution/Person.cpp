#include <iostream>
#include "Person.hpp"

using std::string;

Person::Person(const string& name, size_t age)
    : m_name(name)
    , m_age(age)
{}


void Person::print() const
{
    std::cout << m_name << " is " << m_age << " years old";
}
