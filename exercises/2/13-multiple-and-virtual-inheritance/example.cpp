#include <iostream>
#include <string>


class Person
{
public:
    void print() {
        std::cout << name << " is " << age << " years old.\n";
    }

    std::string name;
    int age;
};


class Student : virtual public Person
{};

// Try removing the virtual keyword
class Teacher : virtual public Person
{};

// Teaching assistant is both a Teacher and a Student
class TA : public Teacher, public Student
{};


int main()
{
    TA s;
    s.name = "Georgi";
    s.age = 25;
    s.print();

    return 0;
}
