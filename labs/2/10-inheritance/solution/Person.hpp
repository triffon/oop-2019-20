#pragma once
#include <string>

class Person
{
    using string = std::string;

public:
    Person(const string& name = "unnamed", size_t age = 0);

    void print() const;
    inline string getName() const { return m_name; }
    inline size_t getAge()  const { return m_age;  }

protected:
    string m_name;
    size_t m_age;
};
