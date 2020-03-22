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
        /// Here this is of type "const Student *"
        int getFacultyNumber() const { return facultyNumber; }

        /// We can either return const char * or allocate new char * in order to protect our data
        const char * getName() const { return name; }

    protected:

    private:
        ///Helper function to avoid duplicating code
        void copyFromOtherStudent(const Student& other);
        ///We don't want everyone to be able to change the name or faculty number of our student
        /// Here this if of type "Student *"
        void setName(char * name);

        void setFacultyNumber(char val) { facultyNumber = val; }

        int facultyNumber;
        char * name = nullptr;

    /// Used for allowing other function to access private data, use with caution!
    friend istream& operator>> (istream& is, Student& s);
    friend ostream& operator<< (ostream& os, Student& s);
    /// allows private access to a class, use with caution!
    /// class University; //when you start a master degree the university assigns you a new facultyNumber thus it requires private access

    /// Important!!!
    /// Friendship isn’t symmetric, transitive ( or inheritable)
    /// I am not a friend of my friend!
    /// The friend of my friend is not a friend

};

#endif // STUDENT_H
