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
    Person & operator=(Person const &);
    ~Person();
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

Person::Person(Person const & p) {
    name = new char[strlen(p.name) + 1];
    strcpy(name, p.name);
    EGN = new char[strlen(p.EGN) + 1];
    strcpy(EGN, p.EGN);
}

Person & Person::operator=(Person const & p) {
    if (&p != this) {
        delete[] name;
        delete[] EGN;
        name = new char[strlen(p.name) + 1];
        strcpy(name, p.name);
        EGN = new char[strlen(p.EGN) + 1];
        strcpy(EGN, p.EGN);
    }
    return *this;
}

Person::~Person() {
    std::cout << "~Person()" << std::endl;
    delete[] name;
    delete[] EGN;
}

void Person::outputPerson() const {
    std::cout << "Ime: " << (name == nullptr ? "<unknown name>" : name) << " EGN: " << (EGN == nullptr ? "<uknown EGN>" : EGN) << std::endl;
}

class Student : protected Person {

public:
    Student();
    Student(const char *, const char *, int, double);
    //Student(Student const &);
    Student & operator=(Student const &);
    ~Student();
    void outputStudent() const;

private:
    int FN;
    double grade;

};

Student::Student() : Person() {
    FN = 0;
    grade = 0;
}

Student::Student(const char * _name, const char * _EGN, int _FN, double _grade) : Person(_name, _EGN) {
    FN = _FN;
    grade = _grade;
}

Student & Student::operator=(Student const & s) {
    if (this != &s) {
        Person::operator=(s);
        FN = s.FN;
        grade = s.grade;
    }
    return *this;
}

Student::~Student() {}

void Student::outputStudent() const {
    outputPerson();
    std::cout << "FN: " << FN << " Grade: " << grade << std::endl;
}

class PStudent : Student {

public:
    PStudent(const char *, const char *, int, double, double);
    ~PStudent();
    void outputPStudent() const;

private:
    double tax;

};

PStudent::PStudent(const char * _name, const char * _EGN, int _FN, double _grade, double _tax) : Student(_name, _EGN, _FN, _grade){
    tax = _tax;
}

PStudent::~PStudent() {}

void PStudent::outputPStudent() const {
    outputStudent();
    std::cout << "Tax: " << tax << std::endl;
}

int main() {
    Student s1("Ivan", "566756757", 80123, 5.5);
    s1.outputStudent();

    PStudent ps1("Georgi", "312312312", 80124, 5.75, 250);
    ps1.outputPStudent();

    Student s2(s1);
    s2.outputStudent();

    Student s3;
    s3.outputStudent();

    Person p1("Ivan", "123456");
    Person p2("Boyan", "123457");

    p1.outputPerson();
    p2.outputPerson();

    p2 = p1 = p1;
    p2.outputPerson();

    s2.outputStudent();
    s3.outputStudent();

    s3 = s2;
    s3.outputStudent();

    return 0;
}