#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

using namespace std;
class Student
{

    public:
        ///Maybe we could even remove this constructor and only leave it with a default one
        Student(char * name = nullptr, int facultyNumber = 0);

        Student(const Student& other);

        Student& operator=(const Student& other);

        ~Student();

        int getFacultyNumber() const { return facultyNumber; }

        /// We can either return const char * or allocate new char * in order to protect our data
        const char * getName() const { return name; }
        /// implicit cast of Student objects to char*
        operator char *() const;
        /// explicit cast of Student objects to char*
        /// explicit operator char *() const;
    protected:

    private:
        void copyFromOtherStudent(const Student& other);

        void setName(char * name);

        void setFacultyNumber(char val) { facultyNumber = val; }

        int facultyNumber;
        char * name = nullptr;

    friend istream& operator>> (istream& is, Student& s);
    friend ostream& operator<< (ostream& os, Student& s);

};

#endif // STUDENT_H
