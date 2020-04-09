#include "Student.h"
#include <cstring>
Student::Student(const char * name)
{
    setName(name);
}

void Student::setFacultyNumber(int facultyNumber){
    this->facultyNumber = facultyNumber;
};
int Student::getFacultyNumber()const{
    return facultyNumber;
};

void Student::setName(const char * name){
    if(name!=nullptr)
        strcpy(this->name,name);
};
const char * Student::getName()const{
    return name;
};
std::istream& operator>>(std::istream& is, Student& s){
    char name[16];
    int facultyNumber;
    is >> name >> facultyNumber;
    s.setName(name);
    s.setFacultyNumber(facultyNumber);
    return is;
}
std::ostream& operator<<(std::ostream& os, Student& s){
    os << s.getName() << " "<< s.getFacultyNumber() << std::endl;
    return os;
}
