#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

class Human {
    char name[32];
    char family[32];
    int age;

public:
    Human() {
        strcpy(this->name, "\0");
        strcpy(this->family, "\0");
        this->age = 0;
    }

    Human(char const* name, char const* family, int age) {
        strcpy(this->name, name);
        strcpy(this->family, family);
        this->age = age;
    }

    void print() {
        cout << "Name: " << name << endl;
        cout << "Family: " << family << endl;
        cout << "Age: " << age << endl;
    }
};

class Student : public Human {
    int facultyNumber;
    char spec[32];

public:
    Student() {
        this->facultyNumber = 0;
        strcpy(this->spec, "\0");
    }

    Student(char const* name, char const* family, int age, int faculty, char const* spec) : Human(name, family, age) {
        this->facultyNumber = faculty;
        strcpy(this->spec, spec);
    }

    void print() {
        Human::print();
        cout << "FN: " << facultyNumber << endl;
        cout << "Spec: " << spec << endl;
    }
};

int main() {
    Student student1;
    student1.print();
    cout << endl;

    Student student2("John", "Doe", 32, 2312, "Informatics");
    student2.print();

    return 0;
}
