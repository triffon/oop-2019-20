#include <iostream>
#include <cstring>

/*

Person -> Student -> PStudent
name      FN         tax
EGN       grade

*/

class Person {

public:
    Person();
    Person(const char *, const char *);
    Person(Person const &);
    ~Person();
    void inputPerson(const char *, const char *);
    void outputPerson() const;

private:
    char * EGN;

protected:
    char * name;
};

Person::Person() {
    EGN = nullptr;
    name = nullptr;
}

Person::Person(const char * _name, const char * _EGN) {
    name = new char[strlen(_name) + 1];
    strcpy(name, _name);
    EGN = new char[strlen(_EGN) + 1];
    strcpy(EGN, _EGN);
}

void Person::inputPerson(const char * _name, const char * _EGN) {
    name = new char[strlen(_name) + 1];
    strcpy(name, _name);
    EGN = new char[strlen(_EGN) + 1];
    strcpy(EGN, _EGN);
}

void Person::outputPerson() const {
    std::cout << "Ime: " << name << " EGN: " << EGN << std::endl;
}

class Student : protected Person {

public:
    void inputStudent(const char *, const char *, int, double);
    void outputStudent() const;

private:
    int FN;
    double grade;

};

void Student::inputStudent(const char * _name, const char * _EGN, int _FN, double _grade) {
    inputPerson(_name, _EGN);
    FN = _FN;
    grade = _grade;
}

void Student::outputStudent() const {
    outputPerson();
    std::cout << "FN: " << FN << " Grade: " << grade << std::endl;
}

class PStudent : protected Student {

public:
    void inputPStudent(const char *, const char *, int, double, double);
    void outputPStudent() const;
    char * getName();

private:
    double tax;

};

char * PStudent::getName() {
    return name;
}

void PStudent::inputPStudent(const char * _name, const char * _EGN, int _FN, double _grade, double _tax) {
    inputStudent(_name, _EGN, _FN, _grade);
    tax = _tax;
}

void PStudent::outputPStudent() const {
    outputStudent();
    std::cout << "Tax: " << tax << std::endl;
}

int main() {
    Student s1;
    s1.inputStudent("Ivan", "566756757", 80123, 5.5);
    s1.outputStudent();

    PStudent ps1;
    ps1.inputPStudent("Georgi", "312312312", 80124, 5.75, 250);
    ps1.outputPStudent();

    std::cout << ps1.getName() << std::endl;
    //std::cout << ps1.name << std::endl;

    return 0;
}