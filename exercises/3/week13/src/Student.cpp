#include "Student.h"
#include <cstring>

Student::Student(char * name, int facultyNumber) : facultyNumber(facultyNumber)
{
    if(name!=nullptr){
        this->name = new char[strlen(name)+1];
        strcpy(this->name,name);
    }
}
Student::operator char *() const{
    return name;
};
void Student::setName(char * name){
    if(this->name!=nullptr)
        delete[] name;
    this->name = new char[strlen(name)+1];
    strcpy(this->name,name);
};
Student::~Student()
{
    delete[] name;
}
Student::Student(const Student& other){
    copyFromOtherStudent(other);
};

Student& Student::operator=(const Student& other){
    copyFromOtherStudent(other);
    return *this;
};

void Student::copyFromOtherStudent(const Student& other){
    this->facultyNumber = other.facultyNumber;
    setName(other.name);
};

istream& operator>> (istream& is, Student& s){
    char name[64];

    is >> name >> s.facultyNumber;
    s.setName(name);
    return is;
};
ostream& operator<< (ostream& os, Student& s){
    os << "Student name: " << s.getName() << endl << "Faculty Number: "<< s.getFacultyNumber() << endl;
};
